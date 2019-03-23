"""
No.203 Remove Linked List Elements
Remove all elements from a linked list of integers that have value val.

解题思路：
双指针处理链表：一个负责移除值，一个负责连接移除后断裂的链表。
"""

# For testing purpose only
from test_linked_list import create_list
from test_linked_list import print_list
from test_linked_list import ListNode
import sys

class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        # First remove all the matched value
        # that at the beginning of the list
        while head != None:
            if head.val == val:
                head = head.next
            else:
                break
        
        if head == None:
            return head
        
        # Then use two pointers.
        #   "connecter" is used to connect the broken 
        #       linked list after remove the value.
        #   "breaker" is used to remove the value.
        connecter = head
        breaker = head.next
        
        while breaker != None:
            if breaker.val == val:
                connecter.next = breaker.next
                breaker = connecter.next
                # No need to point the removed element to a None?
                #   No need, just let the previous node connect to 
                #   the next node and ignore the remove node.
            else:
                connecter = connecter.next
                breaker = breaker.next
        return head

l1 = create_list([1,2,6,3,4,5,6])
s = Solution

if __name__ == "__main__":
    print_list(l1)
    print_list(s.removeElements(s,l1,6))