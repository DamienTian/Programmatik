"""
No.20 Valid Parentheses
"""

# For testing purpose only
import sys

class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        parameters = {"(": ")", "[": "]", "{": "}"}
        current_p = [] # stores the newest parameter in the string
        if s == "":
            return True
        else:
            for p in s:
                if current_p == []:
                    if p in parameters.keys():
                        current_p.append(p)
                    else:
                        return False
                else:
                    last_parameter = current_p[-1]
                    if p not in parameters.keys():
                        if p != parameters[last_parameter]:
                            return False
                        else:
                            current_p.pop()
                    else:
                        current_p.append(p)
        if current_p == []:
            return True
        else:
            return False

s = Solution      

if __name__ == "__main__":
    x = sys.argv[1]
    print(s.isValid(s,x))