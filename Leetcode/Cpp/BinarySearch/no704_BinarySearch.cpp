// ref: https://leetcode.com/problems/binary-search/discuss/202281/c%2B%2B-recursive-and-iterative

#include "../includes.h"

class RecursiveSolution {
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }
    
    int binarySearch(vector<int>& nums, int target, int left, int right){
        if(left > right){
            return -1;
        }
        
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target){
            return mid;
        }
        
        
        else if(nums[mid] < target){
            return binarySearch(nums, target, mid + 1, right);
        }
        else{
            return binarySearch(nums, target, left, mid-1);
        }
    }   
};

class IterationSolution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while(left <= right){
            int mid = left + (right - left) / 2;
            if (nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return -1;
    }
};