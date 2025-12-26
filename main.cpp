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
    cout << string(20, ' ');
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 12);

    cout << string(20, ' ') << string(50, '=') << endl
         << string(20, ' ') << " CRUD File Project " << endl
         << string(20, ' ') << string(50, '=') << endl;
    cout << endl;

    cout << string(20, ' ') << string(50, '-') << endl
         << string(20, ' ') << string(23, '-') << "Menu" << string(23, '-') << endl
         << string(20, ' ') << "| 1- Create a file |" << endl
         << string(20, ' ') << "| 2- Read the file |" << endl
         << string(20, ' ') << "| 3- Update the file |" << endl
         << string(20, ' ') << "| 4- Delete the Records of File |" << endl
         << string(20, ' ') << string(50, '-') << endl;

    
    return 0;
}
