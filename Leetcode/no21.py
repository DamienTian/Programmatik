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

# create a linked list by using list
def create_list(l):
    head = ListNode(l[0])
    pointer = head
    for n in l[1:]:
        pointer.next = ListNode(n)
        pointer = pointer.next
    pointer.next = None
    return head

# print a linked list with integers only
def print_list(l):
    result = ""
    while(l != None): 
        result = result + str(l.val) + "->"
        l = l.next
    result += "None"
    print(result)


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

l1 = create_list([1,2,4,5])
l2 = create_list([1,3,4])

"""
结论：
我自己写的Linkedlist不适用于正确的解法。
LC里面本身的链表结构是什么样的呢？
在LC里面的链表都是：1 -> 2 -> NULL 
（最后一位不会直接填一个数字，而是指向NULL）
"""

s = Solution

if __name__ == "__main__":
    print_list(l1)


