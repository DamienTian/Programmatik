/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
#include <vector>

using namespace std;

// Solution: Binary Search
//  ref: https://www.cnblogs.com/grandyang/p/4217175.html

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right){
            int mid = left+ (right - left) / 2;
            if(nums[mid] < nums[mid + 1])   left = mid + 1;
            else right = mid;
        }
        return left;
    }
};
// @lc code=end

