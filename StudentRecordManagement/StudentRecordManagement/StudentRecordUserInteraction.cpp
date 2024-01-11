#include "stdafx.h"

#include "StudentRecordUserInteraction.h"
#include "StudentRecordFileHandling.h"

// Function to display the menu and get user's choice
void CStudentRecordUserInteraction::getUserChoice(string& filePath,bool isFileEmpty)
{
    std::cout << "Would you like to:\n";
    std::cout << "1. Dump existing data\n";
    std::cout << "2. Add new data\n";
    

    if (isFileEmpty)
    {
        std::cout << "Enter your choice (1 or 2): ";
    }
    else
    {
        std::cout << "3. View Existing data\n";
        std::cout << "Enter your choice (1 ,2 or 3): ";
    }
    // Get user input
    getline(std::cin, choice);

    processChoice(choice, filePath, isFileEmpty);
}

// Function to handle the user's choice
void CStudentRecordUserInteraction::processChoice(string& choice, string& filePath, bool isFileEmpty)
{
    if (choice == "1") {
        
        Debug("You chose to dump existing data.");
        
        fileHandler->dumpDataIntoEmptyCSV(createStudentRecord(), filePath);
    }
    else if (choice == "2") {
       
        Debug("You chose to add new data.");

        fileHandler->dumpDataIntoEmptyCSV(getStudentRecord(), filePath);
    }
    else if (choice == "3" && isFileEmpty == false)
    {
        Debug("You chose to view existing data.");

        fileHandler->viewStudentData(filePath);
    }
    else {
       Error("Invalid choice. Please enter 1 or 2.");

    }
}

//Function to create Student Record
vector<studentRecord> CStudentRecordUserInteraction::createStudentRecord()
{
    vector<studentRecord> records = {
        { "John Doe", "001", "1995-05-15", "Male", "Computer Science" },
        { "Jane Smith", "002", "1996-08-20", "Female", "Electrical Engineering" },
        { "Mike Johnson", "003", "1997-02-10", "Male", "Mechanical Engineering" },
        { "Emily Brown", "004", "1998-04-25", "Female", "Civil Engineering" },
        { "Chris Lee", "005", "1999-06-30", "Male", "Information Technology" }
    };
    return records;
}

//Function to take Student Records from User
vector<studentRecord> CStudentRecordUserInteraction::getStudentRecord()
{
    cout << "Enter number of records you want to add:";

    cin >> noOfStudentsRecords;

    vector<studentRecord> data(noOfStudentsRecords);

    for (int i = 0; i < noOfStudentsRecords; i++)
    {
        cout << "Enter Student Name:";
        cin >> data[i].studentName;

        cout << "Enter Student Id:";
        cin >> data[i].studentId;

        cout << "Enter Student DOB (YYYY-MM-DD):";
        cin >> data[i].studentDOB;

        cout << "Enter Student Gender (Male/Female/Other):";
        cin >> data[i].studentGender;

        cout << "Enter Student Course:";
        cin >> data[i].studentCourse;

    }
    return data;
}