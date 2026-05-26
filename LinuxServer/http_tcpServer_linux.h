#ifndef INCLUDED_HTTP_TCPSERVER_LINUX
#define INCLUDED_HTTP_TCPSERVER_LINUX

#include <stdio.h> //Standard input and output for C
#include <sys/socket.h> //Essential header file for creating network applications providing the fundemental tools for establishing communication channels and exchanging data between networked devices.
#include <arpa/inet.h> //Defines the in_port_t and in_addr_t types.
#include <stdlib.h> //Header file and also the standard library for C programming.
#include <string> //The string library

namespace http
{

    class TcpServer
    {
    public:
        TcpServer(std::string ip_address, int port);
        ~TcpServer();
        void startListen();

    private:
        std::string m_ip_address;
        int m_port;
        int m_socket;
        int m_new_socket;
        //long m_incomingMessage;
        struct sockaddr_in m_socketAddress;
        unsigned int m_socketAddress_len;
        std::string m_serverMessage;

        int startServer();
        void closeServer();
        void acceptConnection(int& new_socket);
        std::string buildResponse();
        void sendResponse();
    };

} // namespace http

#endif