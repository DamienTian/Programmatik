"""
No.27 Remove Element
"""

# 第一种思路：遍历list，遇到值 pop
class Solution1(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        i = 0 
        while i < len(nums):
            n = nums[i]
            if n == val:
                nums.pop(i)
            else:
                i += 1
        return len(nums)

"""
另一种思路：
用两个指针，一个指针顺序扫描所有元素判断当前元素是否是要删除的，
另一个指针一直指向下一个不是要删除元素的位置。
这样相当于把原数组中要删除的数去除后，所有其他数字前移。

来自 https://blog.csdn.net/coder_orz/article/details/51578854
（这个博客还有另外两种思路，但都不太好理解s）
"""            
class Solution2(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        length = 0
        for i in range(len(nums)):
            if nums[i] != val:
                nums[length] = nums[i]
                length += 1
        return length