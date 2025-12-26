
#include "crud.h"

// function to create the file
void createFile(const string &filename)
{
    string word = filename;
    string extract;
    size_t index = word.find('.');
    if (index != string::npos)
    {
        extract = word.substr(index + 1);
    }
    else
    {
        cerr << "Invalid file extension please add the .csv file extension" << endl;
        return;
    }

    if (extract != "csv")
    {
        cerr << "Invalid file extension please add the .csv file extension" << endl;
        return;
    }
    ofstream file(word);
    cout << "File created successfully" << endl;
}

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

// function to delete the file
void deleteRecord(const string &filename, const string rollNumber)
{
    vector<string> lines;
    ifstream file(filename);
    if (!file)
    {
        cerr << "Error opening the file" << endl;
        return;
    }
    bool found = false;
    string line;
    while (getline(file, line))
    {
        if (line.rfind(rollNumber, 0) == 0)
        {
            found = true;
            continue;
        }
        lines.push_back(line);
    }
    file.close();

    // now it is considered a best practice to write the data after changing it
    ofstream updatedData(filename, ios::trunc);

    for (const string &l : lines)
    {
        cout << line << endl;
    }
    updatedData.close();
}