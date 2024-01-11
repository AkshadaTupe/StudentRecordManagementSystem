// StudentRecordManagement.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "StudentRecordFileHandling.h"

int main()
{
    string fileName;

    cout << "Enter file name for Student records: ";
    getline(std::cin, fileName);
    
    CStudentRecordFileHandling* fileHandler = new CStudentRecordFileHandling();
    
    CStudentRecordUserInteraction* user = new CStudentRecordUserInteraction();
    string fileCreated = fileHandler->createCSVFile(fileName);

    bool isFileEmpty = fileHandler->isFileEmpty(fileCreated);

    user->getUserChoice(fileCreated, isFileEmpty);

    return 0;
}

