#pragma once
#include "stdafx.h"
#include "StudentRecordFileHandling.h"
#include "StudentRecordUserInteraction.h"
#include <sstream>

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

void CStudentRecordFileHandling::dumpDataIntoEmptyCSV(const std::vector<studentRecord> &records, string& filePath)
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

void CStudentRecordFileHandling::addUserData(const std::vector<studentRecord> &records, string& filePath)
{
    ofstream file(filePath, std::ios::app);
    if (!file.is_open())
        Error("Error Opening File");

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

void CStudentRecordFileHandling::viewStudentData(string& filePath)
{
    ifstream file(filePath);

    if (!file.is_open())
        Error("Error Opening File");

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string token;

        // Display each token (comma-separated values) in the line
        while (std::getline(iss, token, ',')) {
            std::cout << token << " | ";
        }

        // Move to the next line
        std::cout << std::endl;
    }

    // Close the file
    file.close();
}