// Implement a method to perform basic string compression using the counts of repeated characters.
// For example, the string aabcccccaaa would become a2b1c5a3.
// If the "compressed" string would not become smaller then original string then your method should return original string. 
// You can assume the string has only uppercase and lowercase letters [a - z].

#include <iostream>
#include <string>

std::string convert(const std::string& data)
{
    std::string newString;
    char previousCharacter = data[0];
    int counter = 1;
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i] == data[i+1])
        {
            previousCharacter = data[i];
            counter++;
            continue;
        }

        newString += data[i];
        newString += std::to_string(counter);

        counter = 1;
    }

    return newString;
}

int main()
{
    std::string notConvertedString = "aabcccccaaa";

    const auto convertedString = convert(notConvertedString);

    std::cout << (notConvertedString.size() > convertedString.size() ? convertedString : notConvertedString) << std::endl;

    std::string notConvertedString2 = "abc";

    const auto convertedString2 = convert(notConvertedString2);

    std::cout << (notConvertedString2.size() > convertedString2.size() ? convertedString2 : notConvertedString2) << std::endl;

    return 0;
}