#include "../includes.h"

// ref: http://zxi.mytechroad.com/blog/dynamic-programming/leetcode-198-house-robber/

// Solution 1: top down recursion
//  Time: O(n) - use memorization to prune the recursion
//  Space: O(n)
class Solution1 {
public:
    int rob(vector<int>& nums) {
        // initialize every value as -1
        mem = vector<int>(nums.size(), -1);
        return topDownRecursion(nums, nums.size() - 1);
    }
    
    int topDownRecursion(vector<int>& nums, int index){
        if(index < 0){
            return 0;
        }
        
        // if the mem[index] is larger than 0, that means 
        // the house has been visited
        else if(mem[index] >= 0){
            return mem[index];
        }
        
        return mem[index] = max(topDownRecursion(nums, index - 2) + nums[index], 
                           topDownRecursion(nums, index - 1));
    }
    
private:
    // the memorization to stores the max value of each day
    vector<int> mem;
};

// Solution 2: bottom-up iteration
//  Time: O(n)
//  Space: O(n)
class Solution2 {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        
        // DP mem table 
        vector<int> mem (nums.size(), -1);
        
        // use the simplified if statement to verify the boundaries
        for (int i = 0; i < mem.size(); ++i){
            mem[i] = max((i > 1 ? mem[i - 2] : 0) + nums[i], (i > 0 ? mem[i - 1] : 0));
        }
        
        return mem.back();
    }
};

// Solution 2: bottom-up iteration with space optimization
//  Time: O(n)
//  Space: O(1)
class Solution3 {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        
        // DP mem rolling 
        int dp2 = 0;
        int dp1 = 0;
        
        // use the simplified if statement to verify the boundaries
        for (int i = 0; i < nums.size(); ++i){
            int dp = max(dp2 + nums[i], dp1);
            dp2 = dp1;
            dp1 = dp;
        }
        
        return dp1;
    }
};

int main(){
    char alarm = '\a';
    cout << alarm << "Holy Shit" << endl;
    cout << "void main() doesn't work" << endl;
}