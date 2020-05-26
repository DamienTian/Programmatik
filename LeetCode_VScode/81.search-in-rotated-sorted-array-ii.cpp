/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;

// ref: https://www.cnblogs.com/grandyang/p/4325840.html

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) return true;
            if(nums[mid] < nums[right]){
                if(nums[mid] < target && nums[right] >= target) left = mid + 1;
                else right = mid - 1;
            }
            else if(nums[mid] > nums[right]){
                if(nums[mid] > target && nums[left] <= target)  right = mid - 1;
                else left = mid + 1;
            }
            // this process the duplicated element
            else if(nums[mid] == nums[right])
                // just let right index move left and detect again (left OR right side is balanced)
                --right;
        }

        return false;
    }
};
// @lc code=end

