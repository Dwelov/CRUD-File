
#include "crud.h"

// Function to read the existing file
void readFile(const ifstream &requirefile)
{
    ifstream file("requirefile");
    if (!file)
    {
        cerr << "Error opening file for reading." << endl;
        return;
    }
    string line;
    while (getline(file, line))
    {
        cout << line << endl;
    }
    file.close();
}
