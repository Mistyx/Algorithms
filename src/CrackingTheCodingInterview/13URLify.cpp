// URLify: Write a method to replace all spaces in a string with '%20'.
// You may assume that the string has sufficent space at the end to hold the additional characters,
// and that you are given the 'true' length of the string

#include <iostream>
#include <string>

std::string urlify(const std::string& data, int length)
{
    std::string newString;
    for (int i = 0; i < length; i++)
    {
        if (data[i] == ' ')
        {
            newString += "%20";
            continue;
        }
        newString += data[i];
    }
    return newString;
}

int main()
{
    std::cout << urlify("Mr John Smith    ", 13) << std::endl;
    std::cout << urlify("something here  ", 16) << std::endl;
    std::cout << urlify("additional text can help    ", 24) << std::endl;

    return 0;
}