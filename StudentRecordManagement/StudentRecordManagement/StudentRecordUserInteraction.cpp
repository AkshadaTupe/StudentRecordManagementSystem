#include "stdafx.h"

#include "StudentRecordUserInteraction.h"
#include "StudentRecordFileHandling.h"

// Function to display the menu and get user's choice
void CStudentRecordUserInteraction::getUserChoice(string& filePath)
{
    std::cout << "Would you like to:\n";
    std::cout << "1. Dump existing data\n";
    std::cout << "2. Add new data\n";
    std::cout << "Enter your choice (1 or 2): ";

    // Get user input
    getline(std::cin, choice);

    processChoice(choice, filePath);
}

// Function to handle the user's choice
void CStudentRecordUserInteraction::processChoice(string& choice, string& filePath)
{
    if (choice == "1") {
        Debug("You chose to dump existing data.");
        
       createStudentRecord();

       fileHandler->dumpDataIntoCSV(records, filePath);
    }
    else if (choice == "2") {
        Debug("You chose to add new data.");
        // Add code to handle adding new data
    }
    else {
       Error("Invalid choice. Please enter 1 or 2.");
      
    }
}

//Function to create Student Record
void CStudentRecordUserInteraction::createStudentRecord()
{
     records = {
        { "John Doe", "001", "1995-05-15", "Male", "Computer Science" },
        { "Jane Smith", "002", "1996-08-20", "Female", "Electrical Engineering" },
        { "Mike Johnson", "003", "1997-02-10", "Male", "Mechanical Engineering" },
        { "Emily Brown", "004", "1998-04-25", "Female", "Civil Engineering" },
        { "Chris Lee", "005", "1999-06-30", "Male", "Information Technology" }
    };
}