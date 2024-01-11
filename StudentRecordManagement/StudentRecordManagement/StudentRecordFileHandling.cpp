#pragma once
#include "stdafx.h"
#include "StudentRecordFileHandling.h"
#include "StudentRecordUserInteraction.h"


// Function to check if file is already present with same file Name
bool CStudentRecordFileHandling::fileExits(const std::string &fileName)
{
   
    std::ifstream infile(fileName);
    
    return infile.good();
}

// Function to check if file has data or not
bool CStudentRecordFileHandling::isFileEmpty(const std::string &fileName)
{

    std::ifstream infile(fileName,ios::ate); // Open the file in input mode and seek to the end

    return (infile.tellg() == streampos(0)); // Check if the file size is zero
}

string CStudentRecordFileHandling::createCSVFile(string fileName)
{
    filePath = initialFilePath + fileName + ".csv";

    if (fileExits(filePath))
    {       
        Debug("File with same fileName already exists");

        if(isFileEmpty(filePath))
            Debug("File is Empty");
    }
    else
    {
        // Create a new file using ofstream
        std::ofstream File(filePath);

        if (!File.is_open())
        {
            Error("Error while creating File");
            return NULL;
            exit(EXIT_FAILURE);
        }
        
        Debug("File Successfully Created");
        File.close();
    }
    return filePath;
   
}

void CStudentRecordFileHandling::dumpDataIntoCSV(const std::vector<studentRecord> &records, string& filePath)
{
    ofstream file(filePath);

    if (!file.is_open())
        Error("Error Opening File");

    //write header TO CSV File
    file << "StudentName,StudentId,StudentDOB,StudentGender,StudentCourse" << std::endl;

    //write data to CSV File
    for (const auto &data : records)
    {
        file << data.studentName << ","
            << data.studentId << ","
            << data.studentDOB << ","
            << data.studentGender << ","
            << data.studentCourse << endl;
     }
    file.close();

    Debug("Data has been successfully written into csv file");
}