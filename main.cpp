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
    cout << endl << endl << endl << endl << endl;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 13); // magneta text

    int choice; // variable declaration
    string filename;

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
             << string(20, ' ') << "| 5- Exit the program          " << string(18, ' ') << "|" << endl
             << string(20, ' ') << string(50, '-') << endl;

        // Input
        cout << "\nEnter your choice: ";
        cin >> choice;

        // Switch for menu options
        switch (choice)
        {
        case 1:
            cout << string(20, ' ') << "Enter the name of the file you want to create\n"
                 <<string(20, ' ')<< "(--------but you can create only .csv files------ )\n";

            cin>>filename;
            createFile(filename);
            break;
        
        case 2:
            cout << string(20, ' ') << "Reading the file" << endl;
            cout << string(20, ' ') << "Enter the name of the file you want to read" << endl;
            cin>>filename;
            readFile(filename);
            break;

        case 3:

        case 5:
        cout<<"You are terminating the program"<<endl;
        break;

        default:
            cout << "Invalid choice! Please try again.\n";
            break;
        }

    } while (choice != 5); // loop until user chooses Exit

    return 0;
}
