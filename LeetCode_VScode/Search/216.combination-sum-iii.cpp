/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> current;
        dfs(k, n, result, current, 1);
        return result;
    }

private:
    void dfs(int k, int n, vector<vector<int>>& result, vector<int>& current, int start){
        if(k == 0 && n == 0){
            result.push_back(current);
            return;
        }
        if(k == 0 || n == 0)    return;

        for(int i = start; i <= 9; ++i){
            if(i <= n){
                current.push_back(i);
                dfs(k - 1, n - i, result, current, i + 1);
                current.pop_back();
            }
        }
    }
};
// @lc code=end

