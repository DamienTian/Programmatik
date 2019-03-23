"""
No.66 Plus One
Given a non-empty array of digits representing a non-negative integer, 
plus one to the integer. The digits are stored such that the most 
significant digit is at the head of the list, and each element in the 
array contain a single digit. You may assume the integer does not 
contain any leading zero, except the number 0 itself.
"""

class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        digits = list(reversed(digits))
        add = True
        i = 0
        
        while i < len(digits) and add == True:
            if digits[i] == 9:
                digits[i] = 0
                i += 1
            else:
                digits[i] += 1
                add = False
        if digits[-1] == 0:
            digits.append(1)
        return list(reversed(digits))