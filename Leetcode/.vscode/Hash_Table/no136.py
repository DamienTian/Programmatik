"""
No.136 Single Number

Given a non-empty array of integers, every element 
appears twice except for one. Find that single one.

Note: Your algorithm should have a linear runtime 
complexity. Could you implement it without using extra memory?

Solution1 是使用 Hashtable 的做法，时间空间复杂度都是 O(n)
Solution2 是使用异或的处理方法。空间复杂度是 O(1)

Solution2思路：因为list里面的每个数字必然出现2次，只有一个数字出现一次
    当异或 list 里的每一个数字时，两个相同的数字将会被异或抵消变为零
    与零异或的数字仍是原数字。因为只有一个数字是重复一次的，剩下的数字
    都正好出现了两次，在异或的时候则会全部消掉，只留下出现一次的数字。

idea: Leetcode 136 Solution.
"""

class Solution1(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mem = {}
        for n in nums:
            if n not in mem:
                mem[n] = 1
            else:
                mem[n] += 1
        for i in mem:
            if mem[i] == 1:
                return i

class Solution2(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        a = 0
        for i in nums:
            a ^= i
        return a