#include "crud.h"
#include "search.h"
#include "validation.h"
using namespace std;

int main()
{
    string filename;
    cout << "Enter the filename to read: ";
    cin >> filename;
    readFile(filename); 
    return 0;
}