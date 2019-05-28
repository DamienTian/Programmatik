// ref: https://blog.csdn.net/happyaaaaaaaaaaa/article/details/51495355

#include "../includes.h"

// Solution 1: iteration
// Key: use binary search to find the closet number or the target
// Time: O(lg n)    Space: O(1)
class IterationSolution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while(left < right){
            // This way of finding middle index prevents the infinite loop
            int mid = left + (right - left) / 2;
            
            if (nums[mid] < target){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        
        // return the left index:
        //  if the left index number is smaller than the target, then target should be behind it.
        //  else, target takes place of the left index
        return nums[left] >= target ? left : left + 1;
    }
};

// Solution 2: recursion
// Time: O(lg n)    Space: O(1)
class RecursiveSolution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size()-1);
    }
    
    int binarySearch(vector<int>& nums, int target, int left, int right){
        if (left >= right){
            return nums[left] >= target ? left : left + 1;
        }
        
        int mid = left + (right - left) / 2;
        
        if(nums[mid] < target){
            return binarySearch(nums, target, mid+1, right);
        }
        
        else{
            return binarySearch(nums, target, left, mid);
        }
    }
};