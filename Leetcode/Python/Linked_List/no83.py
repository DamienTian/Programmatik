"""
No.21 Merge Two Sorted Lists:
Given a sorted linked list, delete all 
duplicates such that each element appear 
only once.
"""

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        # When the linked list is None OR only one node:
        if head == None or head.next == None:
            return head
        # Pointer that used to loop the list.
        # Use one pointer as two pointers
        point = head
        while point.next: # is not None.
            if point.val == point.next.val:
                point.next = point.next.next
            else:
                point = point.next
        return head