#include <iostream>
#include <vector>

int search(const std::vector<int>& data, int target, int index)
{
    if (data[index-1] == target)
    {
        return index;
    }
    else if (data[index-1] > target)
    {
        std::cout << "Search left " << index << std::endl;
        return search(data, target, ((index%2 == 0) ? index-(index/2) : index-(index/2)+1));

    }
    else if (data[index-1] < target)
    {
        std::cout << "Search right " << index << std::endl;
        return search(data, target, ((index+(index/2)%2 == 0) ? index+(index/2)-1 : index+(index/2)));
    }

    return -1;
}

int main()
{
    std::vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};

    const auto index = search(data, 10, data.size()/2);

    std::cout << index << std::endl;
    return 0;
}