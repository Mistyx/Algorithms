#include <iostream>
#include <vector>

void sortElements(std::vector<int>& data, double gap)
{
    for (int i = 0; i < data.size()-1; i++)
    {
        if (i + gap >= data.size())
        {
            return;
        }

        if (data[i] > data[i + gap])
        {
            int temp = data[i];
            data[i] = data[i + gap];
            data[i + gap] = temp;
        }
    }
}

void combSort(std::vector<int>& data)
{
    double gap = data.size();

    while (gap > 1)
    {
        std::cout << gap << std::endl;
        sortElements(data, gap);
        gap = gap*10/13;
        std::cout << gap << std::endl;
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

    combSort(data);

    std::cout << "Sorted data: " << std::endl;

    printData(data);
    return 0;
}