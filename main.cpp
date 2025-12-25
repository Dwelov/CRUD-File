#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "crud.h"
#include "search.h"
#include "validation.h"

using namespace std;

int main()
{
    string filename, rollNo, name;
    vector<int> marksList;
    float average;

    cout << "Enter the filename you want to update: ";
    cin >> filename;

    cout << "Now Enter the roll number: ";
    cin >> rollNo;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Now Enter the name of student: ";
    getline(cin, name);
    cout<<endl;

    if (!validateRollNumber(rollNo))
    {
        cerr << "Roll no should be in the format BSAI25011519-(two digit number)" << endl;
        return 1;
    }

    for (int i = 0; i < 7; i++)
    {
        int mark;
        cout << "Enter mark " << i + 1 << ": ";
        cin >> mark;
        marksList.push_back(mark);
    }

    cout << "Now enter the average of the marks: ";
    cin >> average;

    addStudents(filename, rollNo, name, marksList, average);
    
    return 0; 
}
