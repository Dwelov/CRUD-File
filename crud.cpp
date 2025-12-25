
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

void updateRecord(const string &filename, const string &rollNumber, const string &newName,
                  const vector<int> &newMarks, float newAverage)
{
    // first declare the variables that are going to use in that block of the code

    ifstream file(filename);
    vector<string> lines;
    string line;
    bool found = false;

    if (!file)
    {
        cerr << "Error opening the file" << endl;
        return;
    }

    // read and update the line of the code
    while (getline(file, line))
    {
        /*checking the first letter of the line starts with the rollno or not for
         for this purpose i use the rfind function
         it is
                     str.rfind(index,pos)
         it is part of the */
        if (line.rfind(rollNumber, 0) == 0)
        {
            cout << "line to update: " << line << endl;
            ostringstream updated; // stringstring writes in string just liek fstream in files
            updated << rollNumber << "," << newName;
            for (int mark : newMarks)
            {
                updated << "," << mark;
            }
            updated << "," << newAverage << endl;
            lines.push_back(updated.str());
            found = true;
        }
        else
        {
            cout << "Nothing to update " << endl;
            lines.push_back(line);
        }
    }
    file.close();

    // displaying a error message in case the roll number not found
    if (!found)
    {
        cerr << "error updating the file because " << rollNumber << " not found" << endl;
        return;
    }

    // rewriting the updated file
    ofstream updatedFile(filename);
    for (const string &l : lines)
    {
        updatedFile << l << endl;
    }
    updatedFile.close();

    cout << "Student data for the " << rollNumber << " Updated Successfully" << endl;
}
