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
    SetConsoleTextAttribute(hConsole, 12); // red text

    int choice; // variable declaration

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
            cout << "Enter the name of the file you want to create\n"
                 << "(--------but you can create only .csv files------ )\n";
            // call createFile() here
            break;

        case 2:
            cout << "Reading file...\n";
            // call readFile() here
            break;

        case 3:
            cout << "Updating file...\n";
            // call updateFile() here
            break;

        case 4:
            cout << "Deleting records...\n";
            // call deleteFile() here
            break;

        case 5:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
            break;
        }

    } while (choice != 5); // loop until user chooses Exit

    return 0;
}
