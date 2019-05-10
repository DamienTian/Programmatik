#include <iostream>
#include <vector>

using namespace std;

class CStyleSolution
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

// ref of Solution 1 & 2: https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-70-climbing-stairs/
// Solution 1 space complexity: O(n)
class Solution1
{
public:
    int climbStairs(int n)
    {
        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; ++i){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

// Solution 2 space complexity: O(1)
class Solution2 {
public:
     int climbStairs(int n)
    {
        /*
        这里有一点难理解：
        因为这类问题只需要前两步旳值，所以我们只需要存储前两步值即可，不需要存贮每一步的值
        这里有两个存贮：
        - two_step_before：两步前的值
        - one_step_before：一步前的值
        这两个值会随着步数的增加而更新.
        (相同的解法可用于 no.746)
        */
        int two_step_before = 1;
        int one_step_before = 1;
        int current = 1;
        for (int i = 2; i <= n; ++i){
            current = two_step_before + one_step_before;
            two_step_before = one_step_before;
            one_step_before = current;
        }
        return current;
    }
};

int main()
{
    int stairs;
    Solution1 s;

    std::cout << "Enter nubmer of stairs: ";
    std::cin >> stairs;

    std::cout << "Number of way to go: " << s.climbStairs(stairs) << std::endl;
}