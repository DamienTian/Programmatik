// ref: https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-303-range-sum-query-immutable/

#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        int size = nums.size();
        if(size == 0){
            return;
        }
        
        sums_record = vector<int>(size,0);
        // build a 2d nxn vector and initialize every digit as 0
        // sums_record = vector<vector<int> >(n, vector<int>(n,0));
        
        // not need a 2d vector, just use a vector to stores the calculation result
        sums_record[0] = nums[0];
        for (int i = 1; i < size; ++i){
            sums_record[i] = sums_record[i - 1] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        if(i == 0){
            return sums_record[j];
        }
        return sums_record[j] - sums_record[i - 1];
    }
    
private: 
    // a 1d vector to stores the calculation result for index 0 to i
    vector<int> sums_record;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */