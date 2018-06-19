"""
No.26 Remove Duplicates from Sorted Array
Given a sorted array nums, remove the duplicates 
in-place such that each element appear only once 
and return the new length.Do not allocate extra 
space for another array, you must do this by 
modifying the input array in-place with O(1) 
extra memory.

解题思路：因为是已经排序好的，顺着检查重复数量的数字即可。
从开头记录所有重复的数字出现的数量（使用一个指针遍历，指针是一个 index：line 23）
然后将多余的数字移除，将计数器还原为 0 (line 24, 38)
如此遍历整个 list.
"""

class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if nums == [] or nums == None:
            return 0
        c = 0   # The pointer index
        counter = 0
        while c < len(nums) - 1:
            current = nums[c]
            while nums[c] == current:
                counter += 1
                if c < len(nums) - 1:
                    c += 1
                else:
                    break
            if counter >= 1:
                while counter > 1:
                    print(nums.pop(c-1))
                    c -= 1
                    counter -= 1
                counter -= 1    # to restores the counter to 0
        return len(nums)