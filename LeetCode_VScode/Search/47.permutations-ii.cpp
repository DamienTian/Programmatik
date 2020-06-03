/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Solution 1: dfs
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.empty())    return {};

        sort(begin(nums), end(nums));
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> visited(nums.size(), false);
        permute(nums, result, current, visited);
        return result;
    }

    void permute(vector<int>& nums, vector<vector<int>>& result, vector<int>& current, vector<bool>& visited){
        if(current.size() == nums.size()){
            result.push_back(current);
            return;
        }

        for(int i = 0; i < nums.size(); ++i){
            if(visited[i] == true) continue;
            // Same number can be only used once at each depth even the previous element has not been used
            // ref: https://zxi.mytechroad.com/blog/searching/leetcode-47-permutations-ii/
            if(i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == false) continue;
            visited[i] = true;
            current.push_back(nums[i]);
            permute(nums, result, current, visited);
            current.pop_back();
            visited[i] = false;
        }
    }
};
// @lc code=end

