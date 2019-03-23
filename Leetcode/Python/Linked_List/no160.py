"""
No.160 Intersection of Two Linked Lists

Write a program to find the node at which 
the intersection of two singly linked lists 
begins.

Notes:

* If the two linked lists have no intersection at all, return None.
* The linked lists must retain their original structure after the function returns.
* You may assume there are no cycles anywhere in the entire linked structure.
* Your code should preferably run in O(n) time and use only O(1) memory.

解题思路：
将两个链表对齐：如果其中一个长，将其中一个长的指针指向和短的链表开头对齐的位置。
然后从那个位置开始，两个指针同时跑 
    - 若两个指针指向一个node，返还这个node。
    - else, 返还 None。
"""

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def getLength(self, head):
        result = 0
        while head != None:
            result += 1
            head = head.next
        return result
            
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        lenA = self.getLength(headA)
        lenB = self.getLength(headB)
        lenDiff = lenA - lenB
        
        # Move the pointers to a same place:
        # Let the poiner point at the beginning of two same length linked list
        pointerA = headA
        pointerB = headB
        if lenDiff > 0:
            while lenDiff != 0 and pointerA != None:
                pointerA = pointerA.next
                lenDiff -= 1
        elif lenDiff < 0:
            while lenDiff != 0 and pointerB != None:
                pointerB = pointerB.next
                lenDiff += 1
        
        # If one of the linked list reaches to the end.
        if lenDiff != 0:
            return None
        
        # Else, move both pointers parallelly of two linked list.
        while pointerA != None or pointerB != None:
            if id(pointerA) == id(pointerB):
                return pointerA
            else:
                pointerA = pointerA.next
                pointerB = pointerB.next
        return None