#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#pragma comment(lib, "ws2_32.lib")
//#include<iostream>
#include<winsock2.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

#define PORT 80

const char szHost[] = "www.udemy.com"; //Enter the host address here to test against.

int main(const int argc,const char *argv[]) {
	//Initialize the winsock library.
	WSAData wsaData;
	WORD Dllversion = MAKEWORD(2, 1);

	if (WSAStartup(Dllversion, &wsaData)!=0) { //This function will fail if anything is returned other than 0.
		//Note, for futre development, add an actual error message.
		ExitProcess(EXIT_FAILURE);
	}

	//Create Socket: This is a handle, sockets are used for communication between two different machines, through a network.
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);//The parameters are: IF_INET = communicate over the internet, SOCK_STREAM = communcate over TCP, 0 is the protocol, this is a raw socket, no protocol.

	if (sock < 0) {
		ExitProcess(EXIT_FAILURE);
	}

	//Get Server Info
	HOSTENT* host = gethostbyname(szHost); //;  gethostbyaddr(szHost,sizeof(szHost), AF_INET)

	if (host == nullptr) {
		ExitProcess(EXIT_FAILURE);
	}

	//Define server info
	SOCKADDR_IN sin;
	ZeroMemory(&sin, sizeof(sin)); //Used to limit the extra bytes.

	sin.sin_port = htons(PORT); //Converts the 80 port to bigendian value.
	sin.sin_family = AF_INET;
	memcpy(&sin.sin_addr.S_un.S_addr,host->h_addr_list[0],sizeof(sin.sin_addr.S_un.S_addr));

	//Connect to server
	if (connect(sock,(const sockaddr*)&sin,sizeof(sin))!=0) { //Make sure that it does not equal 0;
		ExitProcess(EXIT_FAILURE);
	}

	//Need to send information also: This protocol, http above the protocol tcp.
	//We are going to use a head request, different than a get request. This sends us back information on the server. 
	const char szMsg[] = "HEAD / HTTP/1.0\r\n\r\n"; //This is the actual information we will be sending. "GET / HTTP/1.0\r\n\r\n"     "HEAD / HTTP/1.0\r\n\r\n"
	if (!send(sock, szMsg, strlen(szMsg), 0)) {
		ExitProcess(EXIT_FAILURE);
	}


	//Create two buffers to receive data from the server.
	char szBuffer[4096];
	char szTemp[4096];

	while (recv(sock, szTemp, 4096, 0)) {
		//Concatenate the values from sztemp to szbuffer
		strcat(szBuffer, szTemp);
	}//Will receive data from teh actual socket.

	printf("%s\n", szBuffer);

	closesocket(sock); //close the socket
	//getchar();


	ExitProcess(EXIT_SUCCESS);
}