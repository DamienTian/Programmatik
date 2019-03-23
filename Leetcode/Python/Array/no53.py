"""
No.53 Valid Parentheses

Given an integer array nums, find the contiguous subarray 
(containing at least one number) which has the largest 
sum and return its sum.

思路：当前组合是一列数组。
考虑若当前组合往后连续加而不会比后面一个数小的情况，
若碰到一个数在数组中是组合之和变小，则数组断裂，否则继续加。

idea: https://leetcode.com/problems/maximum-subarray/discuss/142578/Intuitive-way-to-approach-Maximum-Subarray-O(n)
"""

class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result =  float('-Inf')
        c_sum = 0
        for n in nums:
            c_sum = max(n, c_sum + n)
            result = max(result, c_sum)
        return result