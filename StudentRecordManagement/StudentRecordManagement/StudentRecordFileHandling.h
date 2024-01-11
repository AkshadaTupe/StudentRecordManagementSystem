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
    
    void dumpDataIntoCSV(const std::vector<studentRecord> &records, string& filePath);
  
    string filePath;
    
private:
    

    bool fileExits(const std::string &fileName);

    bool isFileEmpty(const string &fileName);
   
};
