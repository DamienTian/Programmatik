"""
No.202 Happy Number
A happy number is a number defined by the following process: 
Starting with any positive integer, replace the number by the 
sum of the squares of its digits, and repeat the process until 
the number equals 1 (where it will stay), or it loops endlessly 
in a cycle which does not include 1. 
Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number 
1^2+9^2=82 
8^2+2^2=68 
6^2+8^2=100 
1^2+0^2+0^2=1

思路：如果一个数字在检测过程中(连乘过程中)出现了重复的数字，那么这个数字一定
     不是 Happy Number，因为乘积循环而不会到 1（判断循环）.

第一种思路是可以用字典储存出现过的数字，若再出现就说明不是 Happy Number.
第二种思路思路判断是否出现循环可能用到大量的额外空间，如果想要压缩空间复杂
度到 O(1)，可以考虑用 *弗洛伊德环检测算法*（Floyd Cycle Detection 
Algorithm）。代码实现的是第二种思路。

idea: https://blog.csdn.net/coder_orz/article/details/51315486

*弗洛伊德环检测算法*: 
主要想法是用两个指针，一快一慢来判断是否有循环。比如一个链表里面是否有循环。
在此题中用于判断是否有重复的数字。
https://zh.wikipedia.org/wiki/Floyd%E5%88%A4%E5%9C%88%E7%AE%97%E6%B3%95 
"""

class Solution(object):
    def isHappy(self, num):
        """
        :type n: int
        :rtype: bool
        """
        slow = fast = num
        while True:
            slow = self.sqrSum(slow)
            fast = self.sqrSum(fast) # a fast pt
            fast = self.sqrSum(fast)
            if slow == fast:    # detects loop
                break
        
        return slow == 1
    
    # Calculating the square sum.
    # This method saves space.
    def sqrSum(self, n):
        result = 0
        while n > 0:
            tmp = n % 10
            result += tmp * tmp
            n /= 10
        return result