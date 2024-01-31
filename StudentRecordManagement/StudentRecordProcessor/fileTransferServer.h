#pragma once
#include "stdafx.h"

class fileTransferServer : public Logger
{
public:

    fileTransferServer();

    ~fileTransferServer();

    int server_SocketDescriptor;
    std::string receiveLine(int socketDescriptor);
    int client_SocketDescriptor;

    sockaddr_in serverAddr;

    sockaddr_in clientAddr;

    void initializeWinSockLibrary();

    void createSocket();

    void setServerAddress();

    void bindSocket();

    void listenToclient();

    void acceptConnection();

    void recieveFile();

    fstream file;

    
};