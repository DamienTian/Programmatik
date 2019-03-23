#include <iostream>

class Solution
{
public:
    int climbStairs(int n)
    {

        int mem[n + 1];
        memset(mem, 0, sizeof(mem));

        // base case
        mem[0] = mem[1] = 1;

        for (int i = 2; i <= n; ++i)
        {
            for (int j = 1; j <= 2; ++j)
            {
                mem[i] += mem[i - j];
            }
        }
        return mem[n];
    }
};

int main()
{
    int stairs;
    Solution s;

    std::cout << "Enter nubmer of stairs: ";
    std::cin >> stairs;

    std::cout << "Number of way to go: " << s.climbStairs(stairs) << std::endl;
}