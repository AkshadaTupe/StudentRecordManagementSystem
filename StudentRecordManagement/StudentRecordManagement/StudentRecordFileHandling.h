#pragma once
#include "stdafx.h"

class CStudentRecordFileHandling : public Logger
{

public:
    CStudentRecordFileHandling() {}

    ~CStudentRecordFileHandling() {}

    fstream File;

    //change path location
    string initialFilePath = "C://Users//320159441//Documents//GitHub//StudentRecordManagementSystem//StudentRecordManagement//StudentRecordManagement//";
    
    string createCSVFile(string fileName);
    
    void dumpDataIntoEmptyCSV(const std::vector<studentRecord> &records, string& filePath);

    void addUserData(const std::vector<studentRecord> &records, string& filePath);
  
    string filePath;
    
    bool isFileEmpty(const string &fileName);

    void viewStudentData(string& filePath);
private:
    

    bool fileExits(const std::string &fileName);

   
   
};
