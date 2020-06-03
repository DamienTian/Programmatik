/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;

// Solution 1: recursive
class Solution1 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty())    return {};

        vector<vector<int>> result;
        vector<bool> visited(nums.size(), false);
        vector<int> current;
        permutation(nums, result, current, visited);
        return result;
    }

    void permutation(vector<int> nums, vector<vector<int>>& result, vector<int>& current, vector<bool>& visited){
        if(current.size() == nums.size()){
            result.push_back(current);
            return;
        }

        for(int i = 0; i < nums.size(); ++i){
            if(visited[i])  continue;
            current.push_back(nums[i]);
            visited[i] = true;
            permutation(nums, result, current, visited);
            current.pop_back();
            visited[i] = false;
        }
    }
};

// Solution 2: iterative
//  ref: https://www.cnblogs.com/grandyang/p/4358848.html
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // result contains a empty vector<int> for initializing single element array
        vector<vector<int>> result{{}};
        // loop throught each number and insert them on different position
        for(int n : nums){
            // loop through all the vector in result
            for(int i = result.size(); i > 0 ; --i){
            /* NOTE: cannot using the loop condition like this:
            for(int i = 0; i < result.size() ; ++i){ 
                becasue the size of the result is changing (getting larger).
                it will cause the infinite loop
            */    
                // take every first vector in the vector and pop it
                vector<int> temp = result.front();
                result.erase(result.begin());
                // insert the number n into each position of the temp vector
                for(int p = 0; p <= temp.size(); ++p){
                    vector<int> newPer = temp;
                    newPer.insert(newPer.begin() + p, n);
                    result.push_back(newPer);
                }
            }
        }

        return result;
    }
};
// @lc code=end

