// StudentRecordManagement.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "StudentRecordFileHandling.h"

int main()
{
    string fileName;

    cout << "Enter file name for Student records: ";
    getline(std::cin, fileName);
    
    CStudentRecordFileHandling* logger = new CStudentRecordFileHandling();
    
    string fileCreated = logger->createCSVFile(fileName);

    CStudentRecordUserInteraction* user = new CStudentRecordUserInteraction();;
    
    user->getUserChoice(fileCreated);

    return 0;
}

