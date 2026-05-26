#include "http_tcpServer_linux.h"

int main()
{
    using namespace http;

    TcpServer server = TcpServer("0.0.0.0", 8080); //Creates the server instance from the TcpServer class.
    server.startListen();

    return 0;
}