#include <iostream>
#include <vector>
#include <algorithm>    // std::swap

void printVector(std::vector<int> res, std::string message)
{
    for (int j = 0; j < res.size(); ++j)
    {
        std::cout << res[j] << "\t";
    }
    std::cout << message <<"\n";
}