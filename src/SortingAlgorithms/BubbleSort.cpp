#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& data)
{
    for (int i = 0; i < data.size(); i++)
    {
        bool hasChangedSomething = false;
        for (int j = 0; j < data.size()-1; j++)
        {
            if (data[j] > data[j+1])
            {
                int temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
                hasChangedSomething = true;
            }
        }

        if (not hasChangedSomething)
        {
            std::cout << "Vector is sorted; nothing to do" << std::endl;
            return;
        }
    }
}

void printData(const std::vector<int>& data)
{
    for (const auto& element : data)
    {
        std::cout << element << " " << std::endl;
    }

    std::cout << std::endl;
}

int main()
{
    std::vector<int> data = {7, 3, 8, 12, 1, 19, 8, 16, 20, 15, 2, 13, 7, 13, 15, 18, 5, 21};

    std::cout << "Not sorted data: " << std::endl;
    printData(data);

    bubbleSort(data);

    std::cout << "Sorted data: " << std::endl;

    printData(data);
    return 0;
}