"""
No.234 Palindrome Linked List
Given a singly linked list, determine if it is a palindrome.
Addition: O(n) time and O(1) space.

要想实现O(1) space, 就不能用list或dict储存。
关键是将后半段链表反转：
    将链表从开头开始，放入一个新的链表，如此反复 （图解见我的OneNote）
"""

# For testing purpose only
from test_linked_list import create_list
from test_linked_list import print_list
from test_linked_list import get_length
from test_linked_list import ListNode
import sys

class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if not head:
            return True

        # First, find the middle point of the list
        middle = float(get_length(head) / 2)
        # Then split the list
        second_half = head
        while middle > 0:
            second_half = second_half.next
            middle -= 1
        
        # Reverse the list here, stores as a linked list
        # But we only apply one head node
        second_half = self.reverseList(second_half)
        # print_list(second_half)
        
        while second_half:
            if head.val != second_half.val:
                return False
            else:
                head = head.next
                second_half = second_half.next
        return True

    def reverseList(self, head):
        new_head = None
        while head != None:
            pointer = head
            head = head.next
            pointer.next = new_head 
            new_head = pointer
        return new_head
        
l1 = create_list([1,2])
l2 = create_list([1,2,2,1])
l3 = create_list([1,2,3,2,1])
l4 = create_list([1,2,2,2,2,2,2,2,2,1])
l5 = create_list([1])

s = Solution

if __name__ == "__main__":
    print(s.isPalindrome(s,l2))

