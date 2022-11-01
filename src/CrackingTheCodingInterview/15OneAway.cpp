// There are three types of edits that can be performed on strings: insert a character, remove a character, or replace a character.
// Given two strings, write a function to check if they are one edit(or zero edits) away

#include <iostream>
#include <string>
#include <cmath>

int isEdited(const std::string& firstString, const std::string& secondString)
{
    int counter = 0;
    int shift = 0;
    if (firstString.size() > secondString.size())
    {
        for (int i = 0; i < firstString.size(); i++)
        {
            std::cout << firstString[i] << ", " << secondString[i-shift] << std::endl;
            if (firstString[i] == secondString[i-shift])
            {
                continue;
            }

            counter++;
            ++shift;
        }
    } 
    else if (firstString.size() < secondString.size())
    {
        for (int i = 0; i < firstString.size(); i++)
        {
            std::cout << firstString[i-shift] << ", " << secondString[i] << std::endl;
            if (firstString[i-shift] == secondString[i])
            {
                continue;
            }

            counter++;
            ++shift;
        }
    }
    else
    {
        for (int i = 0; i < firstString.size(); i++)
        {
            std::cout << firstString[i] << ", " << secondString[i] << std::endl;
            if (firstString[i] == secondString[i])
            {
                continue;
            }

            counter++;
        }
    }

    return counter;
}


bool isOneAway(const std::string& firstString, const std::string& secondString)
{
    int counter = isEdited(firstString, secondString);

    std::cout << counter << std::endl;

    return counter == 0 or counter == 1;
}

int main()
{
    std::string firstString = "pale";
    std::string secondString = "ple";

    std::cout << isOneAway(firstString, secondString) << std::endl;

    return 0;
}