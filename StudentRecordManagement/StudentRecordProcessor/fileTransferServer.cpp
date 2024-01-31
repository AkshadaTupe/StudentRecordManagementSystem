#include "stdafx.h"
#include "fileTransferServer.h"

fileTransferServer::fileTransferServer()
{
    initializeWinSockLibrary();

    createSocket();

    setServerAddress();

    bindSocket();

    listenToclient();

    acceptConnection();
}

void fileTransferServer::initializeWinSockLibrary()
{
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
        Error("WSAStartup failed.");
    else
        Debug("Initialization of Winsock Library is Successfully");
}

void fileTransferServer::createSocket()
{
    server_SocketDescriptor = socket(AF_INET, SOCK_STREAM, 0);

    if (server_SocketDescriptor == INVALID_SOCKET)
        Error("Failed to create socket.");
    else
        Debug("Socket Created Successfully.");
}

void fileTransferServer::setServerAddress()
{
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY; // Listen on any available interface
    serverAddr.sin_port = htons(12345);       // Listen on port 12345
}

void fileTransferServer::bindSocket()
{
    if (bind(server_SocketDescriptor, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
        Error("Failed to bind socket.");
    else
        Debug("Socket Binded Successfully.");
}

void fileTransferServer::listenToclient()
{
    if (listen(server_SocketDescriptor, 3) < 0)
        Error("Listening failed");
    else
        Debug("Socket in Listen State(Max Connection Queue : 3)");
}

void fileTransferServer::acceptConnection()
{
    int clientAddr_len = sizeof(clientAddr);

    if ((client_SocketDescriptor = accept(server_SocketDescriptor, (struct sockaddr *)&clientAddr, &clientAddr_len)) < 0)
        Error("Failed to accept connection.");
    else
        Debug("Connection Accepted Successfully.");

    recieveFile();
}


void fileTransferServer::recieveFile()
{
    char buffer[1024] = { 0 };

    recv(client_SocketDescriptor, buffer, sizeof(buffer), 0);
    printf("Message recieved from client : %s\n", buffer);
}


