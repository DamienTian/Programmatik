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

# get the length of a linked list
def getLength(head):
        result = 0
        while head != None:
            result += 1
            head = head.next
        return result