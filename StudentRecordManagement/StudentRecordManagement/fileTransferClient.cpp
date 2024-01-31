#pragma once
#include "stdafx.h"
#include "fileTransferClient.h"
#include <sstream>

fileTransferClient::fileTransferClient()
{
    initializeWinSockLibrary();

    createSocket();

    setClientAddress();

    connectToSocket();

}

void fileTransferClient::initializeWinSockLibrary()
{
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
        Error ("WSAStartup failed.");
    else
        Debug("Initialization of Winsock Library is Successfully");
}

void fileTransferClient::createSocket()
{
    client_SocketDescriptor = socket(AF_INET, SOCK_STREAM, 0);

    if (client_SocketDescriptor == INVALID_SOCKET)
        Error("Failed to create socket.");
    else
        Debug("Socket Created Successfully");
}

void fileTransferClient::setClientAddress()
{
    clientAddr.sin_family = AF_INET;
    clientAddr.sin_addr.s_addr = INADDR_ANY; // Listen on any available interface
    clientAddr.sin_port = htons(12345);       // Listen on port 12345
    inet_pton(AF_INET, "127.0.0.1", &clientAddr.sin_addr);
}

void fileTransferClient::connectToSocket()
{
    if (connect(client_SocketDescriptor, (sockaddr*)&clientAddr, sizeof(clientAddr)) == SOCKET_ERROR)
        Error("Failed to connect.");
    else
        Debug("Connection Successfull");

    transferFile("C://Users//320159441//Documents//GitHub//StudentRecordManagementSystem//StudentRecordManagement//StudentRecordManagement//student.csv");
}

void fileTransferClient::transferFile(string filePath)
{
    std::ifstream file("C://Users//320159441//Documents//GitHub//StudentRecordManagementSystem//StudentRecordManagement//StudentRecordManagement//studentProfile.csv");
    std::stringstream fileContent;
    fileContent << file.rdbuf();
    std::string csvData = fileContent.str();

    std::cout << "Message sent to Server : " << csvData << "\n";

    int bytesSent = send(client_SocketDescriptor, csvData.c_str(), csvData.size(), 0);

    if (bytesSent == SOCKET_ERROR)
    {
        std::cerr << "Data was not sent" << std::endl;
        exit(EXIT_FAILURE);
    }
    closesocket(client_SocketDescriptor);
}

//void fileTransferClient::sendLine(int socketDescriptor, const std::string& line) {
//    size_t lineSize = line.size();
//    send(socketDescriptor, reinterpret_cast<const char*>(&lineSize), sizeof(lineSize), 0);
//    send(socketDescriptor, line.c_str(), lineSize, 0);
//}