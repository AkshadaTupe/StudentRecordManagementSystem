// StudentRecordProcessor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "fileTransferServer.h"

int main()
{
    fileTransferServer* obj = new fileTransferServer();
    obj->recieveFile();
    return 0;
}

