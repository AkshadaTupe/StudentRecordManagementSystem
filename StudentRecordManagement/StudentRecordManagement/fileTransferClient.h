#pragma once
#include "stdafx.h"

class fileTransferClient : public Logger
{
public:

    fileTransferClient();

    ~fileTransferClient();

    void initializeWinSockLibrary();

    void createSocket();

    void  setClientAddress();

    void connectToSocket();

    int client_SocketDescriptor;

    sockaddr_in clientAddr;

    void transferFile(string filePath);

    void sendLine(int socketDescriptor, const std::string& line);
};