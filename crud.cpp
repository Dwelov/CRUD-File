
#include "crud.h"

// Function to read the existing file
void readFile(const string &filename)
{
    ifstream file(filename);
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

void addStudents(const string &filename, const string &rollNumber, const string &newName,
                 const vector<int> &newMarks, float newAverage)
{
    ofstream file(filename, ios::app); // append mode
    if (!file)
    {
        cerr << "Error: file not found." << endl;
        return;
    }
    // Write the new record in CSV format 
    file << rollNumber << "," << newName;
    for (int mark : newMarks)
    {
        file << "," << mark;
    }
    file << "," << newAverage << "\n";
    file.close();
    cout << "Student record added successfully!" << endl;
}


    