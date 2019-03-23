"""
No.3 Longest Substring Without Repeating Characters
Given a string, find the length of the longest substring without 
repeating characters.

Examples:
Given "abcabcbb", the answer is "abc", which the length is 3.

思路：
1. Solution1
我的解法：遍历一遍字符，一边储存最长的 substring (储存在 longest)，同时
           更新最长长度的值（length）

这道题个关键是如何删除不必要的 substring 来保持最长长度的更新:    
- 我的解法使用了一个哈希表 repeat：用来记录非重复字母的下标位置（index），在发
  现重复的字母后，将最开始出现的，重复的字母的下标位置找出，删除longest中这个字母
  最开始位置之前的 substring。因为我们需要遍历字符来找新的 substring，所以之前
  重复字母的前面的部分需要被删除。
  重点是如何保证哈希表 repeat 能正确存储当前字母的下标位置。

Time: O(n^2)
Space: O(2*n) -> O(n)

2. Solution2: Sliding Window
Leetcode 官方解法2：使用两个指针：i j，一前一后遍历字符，两个指针记录 substring
的前后位置，同时使用一个哈希表记录出现过的字母。指针移动规则如下：
    - i j 初始值为 0, j 在 i 前。
    - 若找到一个新字符（未重复过），将 j 向后方移动。将 j 处的字母加入哈希表，
      同时更新最长长度。
    - 若找到重复字符，则将 i 向后移动一位，并删除哈希表中的对应字母。
      *** 因为 j 在 i 之前，若 j 再向后移动的过程中找到重复字母，则 i 位是重复字母
          的出现位置，故将 i 向后移动。***
    - 直到其中一个指针移动到尾端为止。

Time: O(2n) -> O(n)
Space: O(min(m,n)) (m as the size of the hash)
"""

import sys

class Solution1(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        longest = ""
        length = 0 
        repeat = {} # stores chars index
        
        for c in s:
            longest += c
            if c not in repeat:
                repeat[c] = longest.index(c)
                # length += 1 (Don't add this, but why?)
                if len(longest) > length:
                    length = len(longest) # longest length update
            else:
                # Record the length of substring that need to be removed.
                # Use the 'length_pop' to update the 'repeat'
                length_pop = len(longest[:repeat[c]+1])

                # Update 'repeat': remove all pop chars
                for l in longest[:repeat[c]+1]:
                    if l in repeat and l != c:
                        del repeat[l]
                
                # Updata substring
                longest = longest[repeat[c]+1:]

                # Update 'repeat': move all left char (index) forward.                
                for i in repeat:
                    repeat[i] -= length_pop

                # Update 'repeat': updata last char that was found "repeated".
                if longest != "":
                    repeat[c] = longest.index(c)

        return length

class Solution2(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        i = j = result = 0
        repeat = {}
        while i < len(s) and j < len(s):
            if s[j] not in repeat:
                repeat[s[j]] = True
                j += 1
                result = max(result, j - i)
            else:
                del repeat[s[i]]
                i += 1
        return result

s = Solution1

if __name__ == "__main__":
    x = sys.argv[1]
    print(s.lengthOfLongestSubstring(s,x))