// CheckPermutation: Given two strings, write a method to decide if one is permutation of  the other
#include <iostream>
#include <string>
#include <algorithm>

bool isPermutation(std::string&& firstString, std::string&& secondString)
{
    std::sort(firstString.begin(), firstString.end());
    std::sort(secondString.begin(), secondString.end());

    return firstString == secondString;
}

int main()
{
    std::cout << isPermutation("tymbark", "aktymrb") << std::endl;
    std::cout << isPermutation("pringles", "lginpsre") << std::endl;
    std::cout << isPermutation("lays", "slyb") << std::endl;
    std::cout << isPermutation("nokia", "ikona") << std::endl;

    return 0;
}