#include "http_tcpServer_linux.h"

#include <iostream>
#include <sstream>
#include <unistd.h> //Provides access to the (POSIX) operating system API. POSIX = Portable Operating System Interface set by the IEEE.

namespace
{
    const int BUFFER_SIZE = 30720; //Ensures the buffer is large enough to read all the incoming bytes from the connection. 

    void log(const std::string& message)
    {
        std::cout << message << std::endl;
    }

    void exitWithError(const std::string& errorMessage)
    {
        log("ERROR: " + errorMessage);
        exit(1);
    }
}

namespace http
{

    TcpServer::TcpServer(std::string ip_address, int port) : m_ip_address(ip_address), m_port(port), m_socket(), m_new_socket(),
        //m_incomingMessage(), //Note, this does not look like it was needed.
        m_socketAddress(),
        m_socketAddress_len(sizeof(m_socketAddress)),
        m_serverMessage(buildResponse())
    {
        m_socketAddress.sin_family = AF_INET; //This is the socket family, set to AF_INET.
        m_socketAddress.sin_port = htons(m_port); //This is the port used, usually 80.
        m_socketAddress.sin_addr.s_addr = inet_addr(m_ip_address.c_str()); //Hold the IP Address in network byte order as an unsigned long. The inet_addr() function converts the IP address from a char* to and unsigned long and have it stores in network byte order. 

        if (startServer() != 0) //Initiate start server, checks if it was successful.
        {
            std::ostringstream ss;
            ss << "Failed to start server with PORT: " << ntohs(m_socketAddress.sin_port);
            log(ss.str());
        }
    }

    TcpServer::~TcpServer()
    {
        closeServer();
    }

    //As then name emplies, this starts the server, defines the socket and binds the socket.
    int TcpServer::startServer()
    {
        m_socket = socket(AF_INET, SOCK_STREAM, 0);  //Defines the socket: AF_INET = IPv4 protocol (TCP/IP). SOCK_STREAM = the type of communication structure the socket will allow for this family, full duplex byte streams. 0 is the protocol, there is only one protocol that support sock_stream.
        if (m_socket < 0)
        {
            exitWithError("Cannot create socket");
            return 1;
        }

        if (bind(m_socket, (sockaddr*)&m_socketAddress, m_socketAddress_len) < 0) //Used to tie a socket address to a given socket. The first argument is the socket, the second argument is the socket address, and the third is the length of the socket address object.
        {
            exitWithError("Cannot connect socket to address");
            return 1;
        }

        return 0;
    }

    void TcpServer::closeServer()
    {
        close(m_socket);
        close(m_new_socket);
        exit(0);
    }

    void TcpServer::startListen() //Listens for connections. 
    {
        if (listen(m_socket, 20) < 0) //The first argument is the socket. The second argument is the maximum number of connection threads we want to be able to hold at once. If a client tries to connect when the queue is full, they will get rejected by the server.
        {
            exitWithError("Socket listen failed");
        }

        std::ostringstream ss;
        ss << "\n*** Listening on ADDRESS: " << inet_ntoa(m_socketAddress.sin_addr) << " PORT: " << ntohs(m_socketAddress.sin_port) << " ***\n\n";
        log(ss.str());

        int bytesReceived;

        while (true)
        {
            log("====== Waiting for a new connection ======\n\n\n");
            acceptConnection(m_new_socket);

            char buffer[BUFFER_SIZE] = { 0 };
            bytesReceived = read(m_new_socket, buffer, BUFFER_SIZE); //
            if (bytesReceived < 0)
            {
                exitWithError("Failed to read bytes from client socket connection");
            }

            std::ostringstream ss;
            ss << "------ Received Request from client ------\n\n";
            log(ss.str());

            /*TEST PART
            */

            //std::cout << std::endl;
            //std::cout << bytesReceived << std::endl;
            //std::cout << m_socket << std::endl;
            //std::cout << m_new_socket << std::endl;


            sendResponse();

            close(m_new_socket);
        }
    }

    void TcpServer::acceptConnection(int& new_socket)  
    {
        new_socket = accept(m_socket, (sockaddr*)&m_socketAddress, &m_socketAddress_len); //accept() system call is used to process each connection thread in the queue created by listen() . It does this by creating a new socket with a connection thread, which can be used to receive and send data between the client and the server.
        if (new_socket < 0)
        {
            std::ostringstream ss;
            ss << "Server failed to accept incoming connection from ADDRESS: " << inet_ntoa(m_socketAddress.sin_addr) << "; PORT: " << ntohs(m_socketAddress.sin_port);
            exitWithError(ss.str());
        }
    }

    std::string TcpServer::buildResponse()
    {
        std::string htmlFile = "<!DOCTYPE html><html lang=\"en\"><body><h1> Nicte Sefcik Home </h1><p> Nicte Sefcik is super beautiful and I love her. :) </p></body></html>";
        std::ostringstream ss;
        ss << "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: " << htmlFile.size() << "\n\n"
            << htmlFile;

        return ss.str();
    }

    void TcpServer::sendResponse()
    {
        long bytesSent;

        bytesSent = write(m_new_socket, m_serverMessage.c_str(), m_serverMessage.size()); //Sends the response.

        if (bytesSent == m_serverMessage.size())
        {
            log("------ Server Response sent to client ------\n\n");
        }
        else
        {
            log("Error sending response to client");
        }
    }

} // namespace http
