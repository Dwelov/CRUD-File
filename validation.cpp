#include "validation.h"

bool validateRollNumber(const string &rollNumber)
{
    // Step 1: Must be exactly 15 characters
    if (rollNumber.length() != 15)
        return false;

    // Step 2: First 4 characters must be "BSAI"
    if (rollNumber.substr(0, 4) != "BSAI")
        return false;

    // Step 3: Next 8 characters must be digits
    for (int i = 4; i < 12; i++) {
        if (!isdigit(rollNumber[i]))
            return false;
    }

    // Step 4: Those 8 digits must equal "25011519"
    if (rollNumber.substr(4, 8) != "25011519")
        return false;

    // Step 5: Character at position 12 must be '-'
    if (rollNumber[12] != '-')
        return false;

    // Step 6: Last two characters must be digits
    if (!isdigit(rollNumber[13]) || !isdigit(rollNumber[14]))
        return false;

    // Step 7: Last two digits must be between 01 and 50
    int num = stoi(rollNumber.substr(13, 2));
    if (num < 1 || num > 99)
        return false;

    return true;
}
