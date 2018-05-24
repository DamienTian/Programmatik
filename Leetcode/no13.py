"""
No.13 Roman to Integer
"""

# For testing purpose only
import sys

class Solution:
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        roman_letters = {'I': 1,'V': 5,'X': 10,'L': 50,'C': 100,'D': 500,'M': 1000}

        result = 0 # store result
        i = 0
        # Reverse the roman number for calculation
        calculate_roman = s[::-1]

        while(i <= len(calculate_roman) - 1):
            now = roman_letters[calculate_roman[i]]
            if(i < len(calculate_roman) - 1):
                pre = roman_letters[calculate_roman[i + 1]]
            else:
                return result + now
            # Start the calculation
            if pre < now:
                result += int(now - pre)
                i += 2
            else:
                result += now
                i += 1
        if(i >= len(calculate_roman) - 1):
            return result
        else:
            return result + pre
s = Solution

# Testing
if __name__ == "__main__":
    x = sys.argv[1]
    print(s.romanToInt(s,x))