#include <iostream>
#include <vector>

int search(const std::vector<int>& data, int target, int index_min, int index_max)
{
    int mid = (index_min+index_max)/2;
    if (data[mid-1] == target)
    {
        return mid;
    }
    else if (data[mid-1] > target)
    {
        return search(data, target, index_min, mid);

    }
    else if (data[mid-1] < target)
    {
        return search(data, target, mid, index_max);
    }

    return -1;
}

int main()
{
    std::vector<int> data = {1, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48};

    const auto index = search(data, 16, 0, data.size());

    std::cout << index << std::endl;
    return 0;
}