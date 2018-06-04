"""
No.234 Palindrome Linked List
Given a singly linked list, determine if it is a palindrome.
Addition: O(n) time and O(1) space.
"""

# For testing purpose only
from test_linked_list import create_list
from test_linked_list import print_list
from test_linked_list import ListNode
import sys

class Solution(object):
    def getLength(self, head):
        result = 0
        while head != None:
            result += 1
            head = head.next
        return result
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        pass
        
        
l1 = create_list([1,2])
l2 = create_list([1,2,2,1])
l3 = create_list([1,2,3,2,1])
l4 = create_list([1,2,2,2,2,2,2,2,2,1])

s = Solution

if __name__ == "__main__":
    print_list(l1)
    print_list(l2)
    print_list(l3)

