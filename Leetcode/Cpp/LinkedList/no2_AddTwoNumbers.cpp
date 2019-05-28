
 // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 

#include "../includes.h"

// Solution 1: tranverse both list iterately
//  Time: O(n)  Space: O(n)
// ref: https://www.cnblogs.com/grandyang/p/4129891.html
class IterationSolution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // stores the result
        ListNode* result = new ListNode(-1);
        // the cursor that tranverse the result
        ListNode* cursor = result;
        
        // to check if we need to increment the digit
        bool digitIncrement = false;
        
        while(l1 != nullptr || l2 != nullptr){
            // check if the l1 and l2 are empty or not
            int v1 = l1 ? l1->val : 0;
            int v2 = l2 ? l2->val : 0;
            
            // find the current digit
            int digit = v1 + v2 + (digitIncrement ? 1 : 0);
            
            // find if there are any increment digit:
            digitIncrement = digit >= 10 ? true : false;
            
            // assign the result value
            cursor->next = new ListNode(digit % 10);
            
            // move all the pointer to next
            cursor = cursor->next;
            if(l1 != nullptr){
                l1 = l1->next;
            }
            if(l2 != nullptr){
                l2 = l2->next;
            }
        }
      
        // find if there are any last digit that need to be added
        cursor->next = digitIncrement ? new ListNode(1) : nullptr;
        return result->next;
    }
};

// Solution 2: recursive version
//  Time: O(n)  Space: O(n)
class RecursiveSolution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return helper(l1, l2, false);
    }
    
    ListNode* helper(ListNode* l1, ListNode* l2, bool carry){
        // base case
        if (!l1 && !l2 && !carry){
            return NULL;
        }
        
        // find the number of next digit
        int digit = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + (carry ? 1 : 0);
        
        // find if need increment 1 on next digit
        carry = (digit >= 10) ? true : false;
        
        // assigne the new node and jump to next node
        ListNode* result = new ListNode(digit % 10);
        result->next = helper(l1 ? l1->next : NULL, l2 ? l2->next : NULL, carry);
        
        return result;
    }
};

// Super Fast Solution:
//  This solutionb move the increment digit to one of the list,
//  So we don't need to justify the the carry digit?
class SuperFastSolution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        if(!l1 && !l2) return NULL;
        int c = (l1? l1->val:0) + (l2? l2->val:0);
        ListNode *newHead = new ListNode(c%10);
        ListNode *next = l1? l1->next:NULL;
        c /= 10;
        if(next) {
            next->val += c;
        }
        else if(c) {
            next = new ListNode(c);
        }
        // the order of parameters in addTwoNumbers() can be reversed
        newHead->next = addTwoNumbers(l2? l2->next:NULL, next);
        return newHead;
    }
};