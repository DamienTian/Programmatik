/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Solution 1: DP
//  ref: https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-85-maximal-rectangle/
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty())  return 0;

        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n));
        int result = 0;

        // fulfill the dp by sum connect 1 each row from left to right
        // we get the longest length of each row
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                dp[i][j] = (matrix[i][j] == '1') ? (j == 0 ? 1 : dp[i][j - 1] + 1) : 0;
            }
        }

        // calculate the max range by different height
        //  1) loop through different height
        for(int h = 0; h < m; ++h){
            // 2) loop through different length
            for(int l = 0; l < n; ++l){
                // Q: why pick min length when looping through different height?
                // A: because the length of a rectangle depends on the shortest length
                int minLen = INT_MAX;
                // 3) check height in range [0, m), [1, m)...
                for(int j = h; j < m; ++j){
                    // 4) find the minLen of this column 
                    minLen = min(minLen, dp[j][l]);
                    // 5) if the minLen is 0, it means no rectangle can be forms, break
                    if(minLen == 0)   break;
                    // 6) calculate the max area
                    result = max(minLen * (j - h + 1), result);
                }
            }
        }

        return result;
    }
};
// @lc code=end

