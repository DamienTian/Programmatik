/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start

// ref: https://www.cnblogs.com/grandyang/p/4325648.html
#include <iostream>
#include <vector>

using namespace std;
// Solution 1 : Binary Search
// Method: use the mid value to determine which side is in order:
//         if nums[mid] > nums[right]: left side is sorted;
//         else:    right side is sorted
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) return mid;
            if(nums[mid] < nums[right]){
                // in that case, right side is sorted, search right
                if(nums[mid] < target && nums[right] >= target)    left = mid + 1;
                else right = mid - 1;
            }
            else if(nums[mid] >= nums[right]){
                // in that case, leftt side is sorted, search left
                if(nums[mid] > target && nums[left] <= target)   right = mid - 1;
                else left = mid + 1;
            }
        }

        return -1;
    }
};
// @lc code=end

