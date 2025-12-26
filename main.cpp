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
    cout << endl
         << endl
         << endl
         << endl
         << endl;
    cout << string(20, ' ');
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 12);

    // variable declaration
    int choice;

    do
    {
        cout << string(20, ' ') << string(50, '=') << endl
             << string(20, ' ') << string(15, ' ') << " CRUD File Project  " << string(15, ' ') << endl
             << string(20, ' ') << string(50, '=') << endl;
        cout << endl;

        cout << string(20, ' ') << string(50, '-') << endl
             << string(20, ' ') << string(23, '-') << "Menu" << string(23, '-') << endl
             << string(20, ' ') << "| 1- Create                      |" << string(18, ' ') << endl
             << string(20, ' ') << "| 2- Read the file               |" << string(18, ' ') << endl
             << string(20, ' ') << "| 3- Update the file             |" << string(18, ' ') << endl
             << string(20, ' ') << "| 4- Delete the Records of File  |" << string(18, ' ') << endl
             << string(20, ' ') << "| 5- Exist the program           |" << string(18, ' ') << endl
             << string(20, ' ') << string(50, '-') << endl;

        cout << "Enter the choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the name of the file you wanted to create " << endl
                 << "(--------but you can create only .csv files------- )" << endl;
        }

    } while (choice != 5);

    return 0;
}
