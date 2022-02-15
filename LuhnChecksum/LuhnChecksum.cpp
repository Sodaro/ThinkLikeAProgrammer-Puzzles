#include <iostream>
#include <string>

int computeCheckDigit(std::string numberString)
{
    /* go right to left
     * double every other digit
     * insert the individual result digits to the string checkstring
     * add together all the result digits
     * get the digit that would make the value divisible by 10 (0-9)
    */

    std::string result = "";
    bool doubleSwitch = true;
    for (int i = numberString.length() - 1; i >= 0; i--)
    {
        int number = numberString[i] - '0';
        if (doubleSwitch)
        {
            number *= 2;
        }
        std::string numberstr = std::to_string(number);
        for (int i = numberstr.length() - 1; i >= 0; i--)
        {
            result = numberstr[i] + result;
        }
        doubleSwitch = !doubleSwitch;
    }

    int sum = 0;
    for (int i = 0; i < result.length(); i++)
    {
        sum += result[i] - '0';
    }
    
    if (sum % 10 == 0)
    {
        return 0;
    }
    else
    {
        //((27/10 == 2) * 10) = 20 + 10 = 30
        int upperValue = (sum / 10) * 10 + 10;
        return upperValue - sum;
    }
}

int main()
{
    std::string numberString, computeString;
    int checkDigit;

    std::cout << "Enter a 7 digit sequence: ";
    std::cin >> numberString;

    computeString = numberString.substr(0, numberString.size() - 1);
    checkDigit = computeCheckDigit(computeString);
    
    if (checkDigit == numberString[numberString.length() - 1] - '0')
    {
        std::cout << "Checksum Valid" << std::endl;
    }
    else
    {
        std::cout << "Checksum not valid." << std::endl;
    }
    
    return 0;
}
