// Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures.

#include <iostream>
#include <string>
#include <algorithm>

bool isUniqueSolutionUsingSorting(std::string& word)
{
    std::sort(word.begin(), word.end());

    for (int i = 0; i < word.size()-2; i++)
    {
        if (word[i] == word[i+1])
        {
            return false;
        }
    }


    return true;
}

bool isUniqueSolutionUsingAsciiTable(const std::string& word)
{
    bool charTable[256] = {false};
    for (const auto& letter : word)
    {
        if (charTable[letter] == false)
        {
            charTable[letter] = true;
            continue;
        }

        return false;
    }

    return true;
}

int main()
{
    std::string testString = "sample";
    std::string testString2 = "speech";
    std::string testString3 = "tree";
    std::string testString4 = "deal";

    std::cout << isUniqueSolutionUsingSorting(testString) << std::endl;
    std::cout << isUniqueSolutionUsingSorting(testString2) << std::endl;
    std::cout << isUniqueSolutionUsingSorting(testString3) << std::endl;
    std::cout << isUniqueSolutionUsingSorting(testString4) << std::endl;

    std::cout << std::endl;

    std::cout << isUniqueSolutionUsingAsciiTable(testString) << std::endl;
    std::cout << isUniqueSolutionUsingAsciiTable(testString2) << std::endl;
    std::cout << isUniqueSolutionUsingAsciiTable(testString3) << std::endl;
    std::cout << isUniqueSolutionUsingAsciiTable(testString4) << std::endl;
    return 0;
}