#include "crud.h"
#include "search.h"
#include "validation.h"
using namespace std;

int main()
{
    string index;
    cout << "Enter roll number to search: ";
    cin >> index;
    if(!validateRollNumber(index))
    {
        cout << "Invalid roll number format." << endl;
        return 1;
    }
    search(index);
   
    return 0;
}