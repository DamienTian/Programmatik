"""
No.141 Linked List Cycle
Given a linked list, determine if it has a cycle in it.
Follow up: Can you solve it without using extra space?

解题思路：做两个指针，一快一慢。
因为一快一慢指针遍历链表，如果有循环，快的指针总会追上慢的。
好比两个一快一慢在环形操场上跑步的人：快的总会追上慢的。

Space 是 O(1), 因为两个指针不会占用多与空间。
"""

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if head == None or head.next == None:
            return False
        fast = head   # two pointer:
        slow = head   # one slow, one fast
        while fast != None and fast.next != None:
            fast = fast.next.next
            slow = slow.next
            if id(fast) == id(slow):
                return True
        return False