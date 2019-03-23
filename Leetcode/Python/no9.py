"""
No.9 Palindrome Number
Determine whether an integer is a palindrome. 
An integer is a palindrome when it reads the 
same backward as forward.
"""

# For testing purpose only
import sys

class Solution:
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        reverse_x = str(x)[::-1]
        # result = False
        if(reverse_x == str(x)):
            return True
        else:
            return False

s = Solution

if __name__ == "__main__":
    x = sys.argv[1]
    print(s.isPalindrome(s,x))

