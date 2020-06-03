/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Solution 1: DP
// ref (partial): https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-221-maximal-square/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty())  return 0;

        int m = matrix.size();
        int n = matrix[0].size();

        // stores the longest side of a square
        int result = 0;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                dp[i][j] = matrix[i - 1][j - 1] - '0';
                if(dp[i][j] == 0) continue;

                vector<int> allDirection{dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]};
                dp[i][j] = *min_element(allDirection.begin(), allDirection.end()) + 1;
                result = max(result, dp[i][j]);
            }
        }

        return result * result;
    }
};
// @lc code=end

