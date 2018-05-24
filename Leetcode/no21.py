"""
No.21 Merge Two Sorted Lists:
Merge two sorted linked lists and return 
it as a new list. The new list should be 
made by splicing together the nodes of 
the first two lists.
"""

# For testing purpose only
import sys

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

# My version, too complicated and not right
class Old_Solution:
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        result = ListNode(0) # default is 0
        pointer_result = result
        pointer_1 = l1       # set 2 pointers to point the 
        pointer_2 = l2
        while(isinstance(pointer_1,ListNode) == True and \
                isinstance(pointer_2,ListNode) == True
            ):
            if pointer_1.val < pointer_2.val:
                #print(pointer_1.val)
                pointer_result.val = pointer_1.val
                pointer_1 = pointer_1.next
            else:
                #print(pointer_2.val)
                pointer_result.val = pointer_2.val
                pointer_2 = pointer_2.next
            result_next = ListNode(0)
            pointer_result.next = result_next
            pointer_result = pointer_result.next
        if isinstance(pointer_1, int) and isinstance(pointer_2, ListNode):
            if pointer_1 < pointer_2.val:
                pointer_result.val = pointer_1
                pointer_result.next = pointer_2
            else:
                while(isinstance(pointer_2, ListNode) and pointer_2):
                    pointer_result.val = pointer_2.val
        return result

# create a linked list by using list
def create_list(l):
    head = ListNode(l[0])
    pointer = head
    for n in l[1:-1]:
        pointer.next = ListNode(n)
        pointer = pointer.next
    pointer.next = l[-1]
    return head

# print a linked list with integers only
def print_list(l):
    if isinstance(l,int):
        print(l)
        return
    elif isinstance(l, ListNode):
        print(l.val)
        print_list(l.next)

class Solution:
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if not l1:
            return l2
        if not l2:
            return l1

        current = head = ListNode(0)
        while l1 and l2:
            if l1.val < l2.val:
                current.next = l1
                l1 = l1.next
            else:
                current.next = l2
                l2 = l2.next
            current = current.next # Move the pointer one more to the back
        if l1:
            current.next = l1
        else:
            current.next = l2
        return head.next

l1 = create_list([1,2,4])
l2 = create_list([1,3,4])

"""
结论：
我自己写的Linkedlist不适用于正确的解法。
LC里面本身的链表结构是什么样的呢？
"""