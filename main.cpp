#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <limits>
#include "crud.h"
#include "search.h"
#include "validation.h"

using namespace std;

int main()
{
    // Add some spacing at the start
    cout << endl
         << endl
         << endl;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 10);

    // variable declaration
    int choice;
    string filename, rollNumber, name;
    vector<int> marksList;
    int marks;
    bool validate;
    float average;

    do
    {
        // Header
        cout << string(20, ' ') << string(50, '=') << endl
             << string(20, ' ') << string(15, ' ') << " CRUD File Project  " << string(15, ' ') << endl
             << string(20, ' ') << string(50, '=') << endl;
        cout << endl;

        // Menu
        cout << string(20, ' ') << string(50, '-') << endl
             << string(20, ' ') << string(23, '-') << "Menu" << string(23, '-') << endl
             << string(20, ' ') << "| 1- Create                    " << string(18, ' ') << "|" << endl
             << string(20, ' ') << "| 2- Read the file             " << string(18, ' ') << "|" << endl
             << string(20, ' ') << "| 3- Update the file           " << string(18, ' ') << "|" << endl
             << string(20, ' ') << "| 4- Delete the Records of File" << string(18, ' ') << "|" << endl
             << string(20, ' ') << "| 5- Validate roll No for data " << string(18, ' ') << "|" << endl
             << string(20, ' ') << "| 6- Add the students in file  " << string(18, ' ') << "|" << endl
             << string(20, ' ') << "| 7- Search he data            " << string(18, ' ') << "|" << endl
             << string(20, ' ') << "| 8- Exit the program          " << string(18, ' ') << "|" << endl
             << string(20, ' ') << string(50, '-') << endl;

        // prompting the input from the user for which function he is going to perform
        cout << "\nEnter your choice: ";
        cin >> choice;

        // Switch for menu options
        switch (choice)
        {
        case 1:
            cout << string(20, ' ') << "Enter the name of the file you want to create\n"
                 << string(20, ' ') << "(--------but you can create only .csv files------ ): ";
            cin >> filename;
            createFile(filename);
            break;

        case 2:
            cout << string(20, ' ') << "Reading the file" << endl;
            cout << string(20, ' ') << "Enter the name of the file you want to read: ";
            cin >> filename;
            readFile(filename);
            break;

        case 3:
            cout << string(20, ' ') << "Updating the file" << endl
                 << string(20, ' ') << "The data in tne file is organized in the way to keep the record of the students and their grades " << endl
                 << string(20, ' ') << "To update the file you need to enter the followinng details" << endl
                 << string(20, ' ') << "1- file name" << endl
                 << string(20, ' ') << "2- roll no of the  format BSAI25011519-12 (the digits after - should be 1 to  99)" << endl
                 << string(20, ' ') << "3- the name of the student" << endl
                 << string(20, ' ') << "4-Marks the student Obtained in 7 subjects " << endl
                 << string(20, ' ') << "5-Average of that marks" << endl
                 << string(80, '=') << endl
                 << "I hope that you have read the above statements so lets get started" << endl
                 << "Enter the name of the file you have to update: ";
            cin >> filename;

            cout << string(20, ' ') << "Enter the new roll no: ";
            cin >> rollNumber;

            cout << string(20, ' ') << "Enter the new name: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, name);

            cout << string(20, ' ') << "Now enter the updated marks of the student in order (PF,ICT,ICP,CAG,FE,AP,G.P)" << endl;
            marksList.clear();
            for (int i = 1; i <= 7; i++)
            {
                cout << "Subject-" << i << ": ";
                cin >> marks;
                marksList.push_back(marks);
            }
            cout << "Enter the last thing the average marks" << endl;

            cin >> average;
            validate = validateRollNumber(rollNumber);
            if (!validate)
            {
                cerr << "Roll Number format is incorrect" << endl;
            }
            else
            {
                updateRecord(filename, rollNumber, name, marksList, average);
            }

            break;

        case 4:
            cout << string(20, ' ') << "Enter the name of the file for which you wanted to delete the data: ";
            cin >> filename;
            cout << string(20, ' ') << "Enter the roll no of the student to delete its data: ";
            cin >> rollNumber;
            deleteRecord(filename, rollNumber);
            break;

        case 5:
            cout << "Enter the roll no format to add data in file: ";
            cin >> rollNumber;
            validate = validateRollNumber(rollNumber);
            if(validate){
                cout<<"Roll No format is valid"<<endl;
            }else{
                cerr<<"Invalid ROll Number"<<endl;
            }
            break;

        case 6:
            cout << string(20, ' ') << "Adding the data to the file" << endl
                 << string(20, ' ') << "The data in tne file is organized in the way to keep the record of the students and their grades " << endl
                 << string(20, ' ') << "To add the file you need to enter the followinng details" << endl
                 << string(20, ' ') << "1- File name" << endl
                 << string(20, ' ') << "2- Roll no of the  format BSAI25011519-12 (the digits after - should be 1 to  99)" << endl
                 << string(20, ' ') << "3- the name of the student" << endl
                 << string(20, ' ') << "4-Marks the student Obtained in 7 subjects " << endl
                 << string(20, ' ') << "5-Average of that marks" << endl
                 << string(80, '=') << endl
                 << "I hope that you have read the above statements so lets get started" << endl
                 << "Enter the name of the file you have to update: ";
            cin >> filename;

            cout << string(20, ' ') << "Enter the new roll no: ";
            cin >> rollNumber;

            cout << string(20, ' ') << "Enter the new name: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, name);

            cout << string(20, ' ') << "Now enter the updated marks of the student in order (PF,ICT,ICP,CAG,FE,AP,G.P)" << endl;
            marksList.clear();
            for (int i = 1; i <= 7; i++)
            {
                cout << "Subject-" << i << ": ";
                cin >> marks;
                marksList.push_back(marks);
            }
            cout << "Enter the last thing the average marks" << endl;

            cin >> average;
            validate = validateRollNumber(rollNumber);
            if (!validate)
            {
                cerr << "Roll Number format is incorrect" << endl;
            }
            else
            {
                addStudents(filename, rollNumber, name, marksList, average);
            }

        break;

        case 7:
        cout<<"Enter the file name in which you want to serach the data: ";
        cin>>filename;
        cout<<"Enter the roll number of the student if you want to search the data: ";
        cin>>rollNumber;
        search(filename,rollNumber);
        break;

        case 8:
            cout << "You are terminating the program" << endl;
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
            break;
        }

    } while (choice != 8); // loop until user chooses Exit

    return 0;
}
