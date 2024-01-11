#pragma once
#include "stdafx.h"

using namespace std;

class CStudentRecordFileHandling;

class CStudentRecordUserInteraction : public Logger 
{
public:
    CStudentRecordUserInteraction(){}   //default constructor
    
    ~CStudentRecordUserInteraction() {} //default destructor

    string choice;

    void getUserChoice(string& filePath, bool isFileEmpty);

    vector<studentRecord> createStudentRecord();

    vector<studentRecord> getStudentRecord();

    int noOfStudentsRecords;
private:
    void processChoice(string& choice,string& filePath,bool isFileEmpty);
    
    CStudentRecordFileHandling* fileHandler;

   
};