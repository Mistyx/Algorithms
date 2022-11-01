// Given a string, write a function to check if it is a permutation of a palindrome.
// A palindrome is a word or phrase that is the same forwards and backwards.
// A permutation is rearrangement of letters. The palindrome does not need to be limited to just dictionary words.
// You can ignore casing and non letter characters.

#include <iostream>
#include <string>
#include <algorithm>

bool palindromePermutation(std::string& data)
{
    int maxNumberOfSingleLetters = (data.size()%2 == 0) ? 0 : 1;

    std::sort(data.begin(), data.end());

    std::cout << data << std::endl;

    for (int i = 0; i < data.size(); i++)
    {
        if (data[i] == data[i+1])
        {
            i++;
            continue;
        }

        maxNumberOfSingleLetters--;
    }

    return maxNumberOfSingleLetters == 0;
}

int main()
{
    std::string data = "daniodanio";

    std::cout << palindromePermutation(data) << std::endl;

    return 0;
}