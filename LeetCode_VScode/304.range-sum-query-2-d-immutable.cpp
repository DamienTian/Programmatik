/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 */

// @lc code=start

#include <iostream>
#include <vector>

using namespace std;

// Solution 1: DP
//  Time construct O(m*n)   m is the height, n is the length
//  Time search O(m)
class NumMatrix1 {
public:
    NumMatrix1(vector<vector<int>>& matrix) {
        preprocess.clear();

        if(matrix.empty())   return;

        int m = m_ = matrix.size();
        int n = n_ = matrix[0].size();

        preprocess = vector<vector<int>>(m, vector<int>(n));

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                preprocess[i][j] = (j == 0) ? matrix[i][j] : (preprocess[i][j - 1] + matrix[i][j]);
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(m_ == 0 && n_ == 0)  return 0;

        int result = 0;

        for(int i = row1; i <= row2; ++i){
            result += (col1 == 0) ? preprocess[i][col2] : (preprocess[i][col2] - preprocess[i][col1 - 1]);
        }

        return result;
    }

private:
    // this 2D vector stores the preprocessed matrix
    // which each row represents the sum from pos 0 to n
    // each position = sum(0 : this position)
    vector<vector<int>> preprocess;
    // store the size of matrix
    int m_, n_;
};

// Solution 2: DP from HuaHua
// ref: https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-304-range-sum-query-2d-immutable/
//  Time construct O(m*n)   m is the height, n is the length
//  Time search O(1) 
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        dp.clear();

        if(matrix.empty())  return;

        int m = matrix.size();
        int n = matrix[0].size();

        dp = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));

        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                // see HuaHua's page for more info about calculation
                dp[i][j] = matrix[i - 1][j - 1] +
                        dp[i - 1][j] + dp[i][j - 1] - 
                        dp[i - 1][j - 1];
            }
        }    
    }
    
    // see HuaHua's page for more info about calculation
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2 + 1][col2 + 1] - 
                dp[row2 + 1][col1] - 
                dp[row1][col2 + 1] +
                dp[row1][col1];
    }

private:
    // stores the sum from 0,0 to x,y
    vector<vector<int>> dp;
};
/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

