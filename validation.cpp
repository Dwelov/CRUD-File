#include "validation.h"

bool validateRollNumber(const string &rollNumber)
{
    // as my roll no is the dataset file are in the format BSAI25011519-50
    // Step # 1
    if (rollNumber.length() != 15)
    {
        return false;
    }

    // step # 2-checking first 4 characters
    if (rollNumber.substr(0, 4) != "BSAI")
    {
        return false;
    }

    // step # 3-checking next 8 characters are digits or not
    for (int i = 4; i < 12; i++)
    {
        if (!isdigit(rollNumber[i]))
        {
            return false;
        }
    }

    // step # 4 - checking if the 8 characters are equal to 25011519
    for (int i = 4; i < 12; i++)
    {
        string result;
        result += rollNumber[i];
        if (stoi(result) != 25011519)
        {
            return false;
        }
    }
    // step-5 - checking the 13th character is '-'
    if (rollNumber[13] != '-')
    {
        return false;
    }

    // step # 6 - checking last two characters are digits or not
    for (int i = 13; i <= 15; i++)
    {
        if (!isdigit(rollNumber[i]))
        {
            return false;
        }
    }

    return true;
}