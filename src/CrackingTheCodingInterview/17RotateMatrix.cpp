// Given an image represented by an N x N matrix, where each pixel in the image is represented by an integer,
// write a method to rotate the image by 90 degree.
// Can you do this in place?

#include <vector>
#include <iostream>
#include <cmath>

void printMatrix(const std::vector<int>& data)
{
    for (int i = 1; i < data.size()+1; i++)
    {
        if (i%static_cast<int>(sqrt(data.size())) == 0)
        {
            std::cout << data[i-1] << std::endl;
            continue;
        }
        if (data[i-1] >= 10)
        {
            std::cout << data[i-1] << " ";
        }
        else
        {
            std::cout << data[i-1] << "  ";
        }
    }
}

void rotateEdges(std::vector<int>& data, const int offset)
{
    if (data.size() < 4)
    {
        return;
    }

    const int sqrt_ = sqrt(data.size());

    for (int i = 1; i < sqrt_-((offset+1)*2)+1; i++)
    {
        int temp = data[i+offset+offset*sqrt_];
        data[i+offset+offset*sqrt_] = data[sqrt_*(sqrt_-i-offset-1)+offset];
        data[sqrt_*(sqrt_-i-offset-1)+offset] = data[data.size()-1-i-offset-(offset*sqrt_)];
        data[data.size()-1-i-offset-(offset*sqrt_)] = data[sqrt_-1+(i+offset)*sqrt_-offset];
        data[sqrt_-1+(i+offset)*sqrt_-offset] = temp;
    }
}

void rotateCorners(std::vector<int>& data, const int offset)
{
    const int sqrt_ = sqrt(data.size());

    int temp = data[offset*sqrt_+offset];
    data[offset*sqrt_+offset] = data[(sqrt_-offset)*(sqrt_-1)];
    data[(sqrt_-offset)*(sqrt_-1)] = data[data.size()-1-(offset*(sqrt_+1))];
    data[data.size()-1-(offset*(sqrt_+1))] = data[(sqrt_-1)+(offset*(sqrt_-1))];
    data[(sqrt_-1)+(offset*(sqrt_-1))] = temp;
}

void rotateMatrix(std::vector<int>& data)
{
    const int sqrt_ = sqrt(data.size());

    for (int i = 0; i < sqrt_/2; i++)
    {
        rotateCorners(data, i);
        printMatrix(data);
        rotateEdges(data, i);

        printMatrix(data);
    }
}

int main()
{
    std::vector<int> data = {1, 2, 3, 4, 5, 6, 7,
                             8, 9, 10, 11, 12, 13,
                             14, 15, 16, 17, 18, 19,
                             20, 21, 22, 23, 24, 25,
                             26, 27, 28, 29, 30, 31,
                             32, 33, 34, 35, 36, 37,
                             38, 39, 40, 41, 42, 43,
                             44, 45, 46, 47, 48, 49};
    printMatrix(data);

    rotateMatrix(data);

    std::cout << "\nRotating!\n" << std::endl;

    printMatrix(data);
}