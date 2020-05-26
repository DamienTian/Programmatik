/*
 * @lc app=leetcode id=852 lang=cpp
 *
 * [852] Peak Index in a Mountain Array
 */

// @lc code=start
#include <vector>

using namespace std;


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int left = 0, right = A.size() - 1;
        while(left < right){
            int mid = left+ (right - left) / 2;
            if(A[mid] > A[mid + 1]) right = mid;
            else    left = mid + 1;
        }
        return right;
    }
};
// @lc code=end

