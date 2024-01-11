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

    vector<studentRecord> records;

    void getUserChoice(string& filePath);

    void createStudentRecord();

private:
    void processChoice(string& choice,string& filePath);
    
    CStudentRecordFileHandling* fileHandler;

   
};