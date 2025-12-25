#ifndef CRUD_CPP
#define CRUD_CPP
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
// Function to read the existing file
void readFile(const string &filename);
void addStudents(const string &filename, const string &rollNumber, const string &newName,
                 const vector<int> &newMarks, float newAverage);

#endif