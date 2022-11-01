#include <iostream>
#include <vector>

std::vector<int> insertionSort(std::vector<int>& data)
{
    std::vector<int> sortedData;

    for (int i = 0; i < data.size(); i++)
    {
        for (int j = 0; j < data.size(); j++)
        {
            if (i == 0 and j == 0)
            {
                sortedData.push_back(data[0]);
                break;
            }

            if (j == sortedData.size())
            {
                sortedData.push_back(data[i]);
                break;
            }

            if (data[i] < sortedData[j])
            {
                sortedData.insert(sortedData.begin()+j, data[i]);
                break;
            }
        }
    }

    return sortedData;
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

    const auto sorted = insertionSort(data);

    std::cout << "Sorted data: " << std::endl;

    printData(sorted);
    return 0;
}