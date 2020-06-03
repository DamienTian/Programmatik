/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>    // std::min

using namespace std;

// Solution 1: divide and conqure (binary search)
// ref: https://zxi.mytechroad.com/blog/leetcode/leetcode-153-find-minimum-in-rotated-sorted-array/
class Solution1 {
public:
    int findMin(vector<int>& nums) {
        return findMin(nums, 0, nums.size() - 1);
    }

    int findMin(const vector<int> nums, int left, int right){
        // if only two element left in the array
        if(left + 1 >= right)   return min(nums[left], nums[right]);

        // use the property of the sorted array to find the max
        if(nums[left] < nums[right])    return nums[left];

        int mid = left + (right - left) / 2;

        return min(findMin(nums, left, mid), findMin(nums, mid + 1, right));  
    }
};

// Solution 2: Binary Search
// ref: https://www.cnblogs.com/grandyang/p/4032934.html
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while(left < right){
            int mid = left + (right - left) / 2;
            // if mid num is smaller than the rightest element, 
            // it means the min is in the left side becasue the right side is sorted.
            // so search the left side.
            if(nums[mid] < nums[right]) right = mid;
            // if right side is not sorted, search right
            else    left = mid + 1;
        }

        return nums[right];
    }
};


// @lc code=end

