#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// ref for Solution 1 & 2 & recursive: https://www.cnblogs.com/grandyang/p/8343874.html
// NOTE：ref 里面还有一个空间优化的方法很巧妙，但不好想，暂时不写，回去再看。

/*
这道题应该算是之前那道 Climbing Stairs 的拓展，这里不是求步数，而是每个台阶上都有一个cost，
让我们求爬到顶端的最小cost是多少。换汤不换药，还是用动态规划Dynamic Programming来做。

这里我们定义一个一维的dp数组，其中dp[i]表示爬到第i层的最小cost，然后我们来想dp[i]如何推导。

我们来思考一下如何才能到第i层呢？是不是只有两种可能性，一个是从第i-2层上直接跳上来，一个是从第i-1层上跳上来。
不会再有别的方法，所以我们的dp[i]只和前两层有关系，所以可以写做如下：

dp[i] = min(dp[i- 2] + cost[i - 2], dp[i - 1] + cost[i - 1])

最后我们返回最后一个数字dp[n]即可，参见代码如 Solution1：*/

class Solution1 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // memoization for total costs of the paths before
        // why extra length? because you need to record the total cost when reach the top
        vector<int> dp(cost.size() + 1, 0); 
        for (int i = 2; i <= cost.size(); ++i){
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp.back();
    }
};


/*
再来看一种DP的解法，跟上面的解法很相近，不同在于dp数组长度为n，其中dp[i]表示到第i+1层的最小cost，
分别初始化dp[0]和dp[1]为cost[0]和cost[1]。然后从i=2处开始遍历，此时我们的更新思路是，要爬当前的台阶，
肯定需要加上当前的cost[i]，那么我们还是要从前一层或者前两层的台阶上跳上来，那么我们选择dp值小的那个，
所以递归式如下：

dp[i] = cost[i] + min(dp[i- 1], dp[i - 2])

最后我们在最后两个dp值中选择一个较小的返回即可，参见代码如 Solution2：*/

class Solution2 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // memoization for total costs of the paths before
        // why extra length? because you need to record the total cost when reach the top
        vector<int> dp(cost.size(), 0); 
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < cost.size(); ++i){
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        // 为什么这么return？
        // 因为在最后一位的 dp 没有意义，最后一位抵达没有cost，整体 cost 取决于之前的 cost
        return min(dp[cost.size() - 1], dp[cost.size() - 2]);
    }
};

class RecursiveSolution{
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // used for tracking the cost at each stages.
        unordered_map<int, int> dp;
        return helper(cost, cost.size(), dp);
    }
    
    /* takes:
        - the cost array
        - the stage that you want to get the min total cost of
        - the memoization table
       return: the min cost at the stage
    */
    int helper(vector<int>& cost, int stage, unordered_map<int, int>& memo){
        if (memo.count(stage)){
            return memo[stage];
        }
        if(stage <= 1){
            return cost[stage];
        }
        return memo[stage] = (stage == cost.size() ? 0 : cost[stage]) + 
                            min(helper(cost, stage - 1, memo), helper(cost, stage - 2, memo));
    }
};

int main(){
    cout << "本题前两种的算法的时间空间复杂度都是 O(n), 因为都遍历了一便 vector 并且都有一个 n size 的 vector 作为 memoization." << endl;
    cout << "本题递归方法贼慢，不需要用" << endl;
    return 0;
}