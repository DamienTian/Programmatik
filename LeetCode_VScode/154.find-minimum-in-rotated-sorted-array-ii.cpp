/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 */

// @lc code=start

#include <iostream>
#include <vector>
#include <algorithm>    // std::min

using namespace std;

// Solution 1: binary search
//  NOTE: follow the principle of Question 81
class Solution1 {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] < nums[right]) right = mid;
            else if(nums[mid] > nums[right])    left = mid + 1;
            else    --right;   
        }

        return nums[right];
    }
};

// Solution 2: divide and conqure
//  ref: https://zxi.mytechroad.com/blog/divide-and-conquer/leetcode-154-find-minimum-in-rotated-sorted-array-ii/
class Solution {
public:
    int findMin(vector<int>& nums){
        return devideAndConqure(nums, 0, nums.size() - 1);
    }

    int devideAndConqure(vector<int>& nums, int left, int right){
        if(left >= right)   return min(nums[left], nums[right]);
        // NOTE: because the array has duplicated values in array
        //      so you cannot detect if the nums[left] is the smallest when 
        //      the array contains duplicated value.
        if(nums[left] < nums[right])    return nums[left];

        int mid = left + (right - left) / 2;

        // while(nums[mid] == nums[right]){
        //     --right;
        // }

        return min(devideAndConqure(nums, left, mid),
                    devideAndConqure(nums, mid + 1, right));
    }
};
// @lc code=end

