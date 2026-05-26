



//int main() {

//	std::cout << "Babbage Database";

	
//	return 0;
//}

// tls_async_server.cpp
// Cross-platform async TLS echo server with back-pressure, thread pool, timeouts, and graceful shutdown.

#if defined(_WIN32)
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0A00  // Target Windows 10+
#endif
#define NOMINMAX
#endif

#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/asio/signal_set.hpp>
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <array>
#include <atomic>
#include <memory>
#include <chrono>
#include <functional>
#include <algorithm>
#include <csignal>

namespace asio = boost::asio;
using tcp = asio::ip::tcp;
namespace ssl = asio::ssl;
using namespace std::chrono_literals;

class Server; // forward

class Session : public std::enable_shared_from_this<Session> {
public:
    using OnStop = std::function<void()>;

    Session(tcp::socket socket,
        ssl::context& ssl_ctx,
        asio::io_context& io,
        std::chrono::milliseconds idle_timeout,
        OnStop on_stop_cb)
        : stream_(std::move(socket), ssl_ctx),
        idle_timer_(io),
        idle_timeout_(idle_timeout),
        on_stop_(std::move(on_stop_cb))
    {
    }

    void start() {
        auto self = shared_from_this();

        // Socket tuning (optional; safe on both platforms)
        try {
            stream_.lowest_layer().set_option(tcp::no_delay(true));
            stream_.lowest_layer().set_option(asio::socket_base::keep_alive(true));
        }
        catch (...) { /* best-effort */ }

        // Start TLS handshake (server)
        stream_.async_handshake(ssl::stream_base::server,
            [self](const boost::system::error_code& ec) {
                if (!ec) {
                    self->arm_idle_timer();
                    self->do_read();
                }
                else {
                    self->log("Handshake error: " + ec.message());
                    self->stop();
                }
            });
    }

private:
    void do_read() {
        auto self = shared_from_this();
        stream_.async_read_some(asio::buffer(buffer_),
            [self](const boost::system::error_code& ec, std::size_t n) {
                if (!ec) {
                    self->arm_idle_timer();           // activity: refresh timeout
                    self->do_write(n);
                }
                else if (ec == asio::error::eof) {
                    self->log("Peer closed");
                    self->stop();
                }
                else if (ec != asio::error::operation_aborted) {
                    self->log("Read error: " + ec.message());
                    self->stop();
                }
            });
    }

    void do_write(std::size_t n) {
        auto self = shared_from_this();
        asio::async_write(stream_, asio::buffer(buffer_.data(), n),
            [self](const boost::system::error_code& ec, std::size_t /*written*/) {
                if (!ec) {
                    self->arm_idle_timer();           // activity: refresh timeout
                    self->do_read();
                }
                else if (ec != asio::error::operation_aborted) {
                    self->log("Write error: " + ec.message());
                    self->stop();
                }
            });
    }

    void arm_idle_timer() {
        if (idle_timeout_.count() <= 0) return;
        auto self = shared_from_this();
        idle_timer_.expires_after(idle_timeout_);
        idle_timer_.async_wait([self](const boost::system::error_code& ec) {
            if (!ec) {
                self->log("Idle timeout");
                self->stop();
            }
            });
    }

    void stop() {
        // Cancel pending ops/timer, then close the socket cleanly.
        boost::system::error_code ig;
       
        //idle_timer_.cancel(ig); Note: This is causing the code to fail. Might need to reintroduce.

        // Attempt TLS shutdown (may fail if peer already closed)
        try {
            stream_.shutdown(ig);
        }
        catch (...) {}

        stream_.lowest_layer().shutdown(tcp::socket::shutdown_both, ig);
        stream_.lowest_layer().close(ig);

        // Notify server that this session is done.
        if (on_stop_) on_stop_();
        on_stop_ = nullptr; // ensure only once
    }

    void log(const std::string& s) const {
        // Minimal logging to stderr; replace with structured logging as needed.
        std::cerr << "[session " << this << "] " << s << "\n";
    }

    ssl::stream<tcp::socket>     stream_;
    asio::steady_timer           idle_timer_;
    std::chrono::milliseconds    idle_timeout_;
    std::array<char, 4096>       buffer_{};
    OnStop                       on_stop_;
};

class Server {
public:
    Server(asio::io_context& io,
        unsigned short port,
        const std::string& cert_file,
        const std::string& key_file,
        bool require_client_cert,
        const std::string& ca_file,
        int threads,
        int max_sessions,
        std::chrono::milliseconds idle_timeout)
        : io_(io),
        ssl_ctx_(ssl::context::tls_server),
        acceptor_(io),
        signals_(io, SIGINT, SIGTERM
#ifdef SIGQUIT
            , SIGQUIT
#endif
        ),
        max_sessions_(max_sessions > 0 ? max_sessions : 1024),
        idle_timeout_(idle_timeout)
    {
        configure_tls(cert_file, key_file, require_client_cert, ca_file);
        configure_acceptor(port);
        wire_signals();

        // Launch a worker pool for io_context
        int pool = threads > 0 ? threads
            : std::max(1u, std::thread::hardware_concurrency());
        workers_.reserve(pool);
        for (int i = 0; i < pool; ++i) {
            workers_.emplace_back([this] { io_.run(); });
        }

        do_accept();
        std::cerr << "[server] Ready. Threads=" << pool
            << " MaxSessions=" << max_sessions_
            << " IdleTimeout(ms)=" << idle_timeout_.count() << "\n";
    }

    ~Server() {
        // Stop io and join workers
        boost::system::error_code ig;
        acceptor_.close(ig);
        io_.stop();
        for (auto& t : workers_) if (t.joinable()) t.join();
    }

private:
    void configure_tls(const std::string& cert,
        const std::string& key,
        bool require_client_cert,
        const std::string& ca_file)
    {
        ssl_ctx_.set_options(ssl::context::default_workarounds
            | ssl::context::no_sslv2
            | ssl::context::no_sslv3);

#if defined(TLS1_2_VERSION)
        ::SSL_CTX_set_min_proto_version(ssl_ctx_.native_handle(), TLS1_2_VERSION);
#endif

        ssl_ctx_.use_certificate_chain_file(cert);
        ssl_ctx_.use_private_key_file(key, ssl::context::file_format::pem);

        if (require_client_cert) {
            ssl_ctx_.set_verify_mode(ssl::verify_peer | ssl::verify_fail_if_no_peer_cert);
            if (!ca_file.empty()) {
                ssl_ctx_.load_verify_file(ca_file);
            }
            else {
                // If you enable client auth, you should load a CA; otherwise verification will fail.
                std::cerr << "[server] WARNING: require_client_cert=1 but no CA file provided.\n";
            }
        }
        else {
            ssl_ctx_.set_verify_mode(ssl::verify_none);
        }
    }

    void configure_acceptor(unsigned short port) {
        tcp::endpoint ep(tcp::v4(), port);
        boost::system::error_code ec;

        acceptor_.open(ep.protocol(), ec);
        if (ec) throw std::runtime_error("open: " + ec.message());

        acceptor_.set_option(asio::socket_base::reuse_address(true), ec);
        if (ec) std::cerr << "[server] reuse_address set failed: " << ec.message() << "\n";

        acceptor_.bind(ep, ec);
        if (ec) throw std::runtime_error("bind: " + ec.message());

        acceptor_.listen(asio::socket_base::max_listen_connections, ec);
        if (ec) throw std::runtime_error("listen: " + ec.message());

        std::cerr << "[server] Listening on 0.0.0.0:" << port << "\n";
    }

    void wire_signals() {
        signals_.async_wait([this](const boost::system::error_code&, int sig) {
            std::cerr << "[server] Signal " << sig << " received. Stopping acceptor...\n";
            boost::system::error_code ig;
            acceptor_.close(ig);     // stop taking new connections
            // Let active sessions drain; io_context will stop when work finishes
            });
    }

    void do_accept() {
        acceptor_.async_accept([this](const boost::system::error_code& ec, tcp::socket socket) {
            if (!acceptor_.is_open()) return; // shutting down

            if (!ec) {
                //const auto remote = socket.remote_endpoint(ec);
                boost::system::error_code ep_ec;
                const auto remote = socket.remote_endpoint(ep_ec);
                if (!ep_ec) {
                    std::cerr << "[server] Accepted " << remote.address().to_string()
                        << ":" << remote.port() << "\n";
                }

                // Back-pressure: enforce max_sessions cap
                if (active_sessions_.load(std::memory_order_relaxed) >= max_sessions_) {
                    std::cerr << "[server] At capacity (" << max_sessions_
                        << "). Rejecting new connection.\n";
                    boost::system::error_code ig;
                    socket.shutdown(tcp::socket::shutdown_both, ig);
                    socket.close(ig);
                }
                else {
                    // Create session; increment count when it starts
                    active_sessions_.fetch_add(1, std::memory_order_relaxed);

                    auto on_stop = [this]() {
                        const auto n = active_sessions_.fetch_sub(1, std::memory_order_relaxed) - 1;
                        if ((n % 50) == 0) { // occasional metric
                            std::cerr << "[server] Active sessions: " << n << "\n";
                        }
                        };

                    auto sess = std::make_shared<Session>(
                        std::move(socket), ssl_ctx_, io_, idle_timeout_, std::move(on_stop));
                    sess->start();
                }
            }
            else {
                if (ec != asio::error::operation_aborted) {
                    std::cerr << "[server] Accept error: " << ec.message() << "\n";
                }
            }

            // Continue accepting if still open
            if (acceptor_.is_open()) do_accept();
            });
    }

    asio::io_context& io_;
    ssl::context           ssl_ctx_;
    tcp::acceptor          acceptor_;
    asio::signal_set       signals_;
    std::vector<std::thread> workers_;

    std::atomic<int>       active_sessions_{ 0 };
    const int              max_sessions_;
    const std::chrono::milliseconds idle_timeout_;
};

int main(int argc, char* argv[]) {
    // Usage: <port> <cert.pem> <key.pem> [threads] [max_sessions] [idle_timeout_ms] [require_client_cert 0|1] [ca_file]
    if (argc < 4 || argc > 9) {
        std::cerr << "Usage:\n  " << argv[0]
            << " <port> <cert.pem> <key.pem> [threads] [max_sessions]"
            << " [idle_timeout_ms] [require_client_cert 0|1] [ca_file]\n";
        return 1;
    }

    try {
        unsigned short port = static_cast<unsigned short>(std::stoi(argv[1]));
        const std::string cert_file = argv[2];
        const std::string key_file = argv[3];

        int threads = (argc >= 5) ? std::stoi(argv[4]) : 0;
        int max_sessions = (argc >= 6) ? std::stoi(argv[5]) : 1024;
        auto idle_ms = (argc >= 7) ? std::stoi(argv[6]) : 300000; // default 5 min
        bool require_cc = (argc >= 8) ? (std::stoi(argv[7]) != 0) : false;
        std::string ca = (argc >= 9) ? argv[8] : "";

        asio::io_context io;
        Server server(io, port, cert_file, key_file, require_cc, ca,
            threads, max_sessions, std::chrono::milliseconds(idle_ms));

        // The io_context runs on the worker threads created by Server.
        // Keep the main thread alive until process is terminated.
        for (;;) std::this_thread::sleep_for(60s);
    }
    catch (const std::exception& e) {
        std::cerr << "Fatal: " << e.what() << "\n";
        return 2;
    }
}
