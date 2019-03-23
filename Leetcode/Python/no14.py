"""
No.14 Longest Common Prefix
"""

# For testing purpose only
import sys

import collections

class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not strs:
            return ''
        res = ''
        for i in range(len(strs[0])): # loop the first word
            for j in range(1, len(strs)):
                if i >= len(strs[j]) or strs[j][i] != strs[0][i]:
                    return res # if find a not equal char in the list
            res += strs[0][i]
        return res             
            
s = Solution

# Testing
if __name__ == "__main__":
    x = sys.argv[1:]
    print(s.longestCommonPrefix(s,x))