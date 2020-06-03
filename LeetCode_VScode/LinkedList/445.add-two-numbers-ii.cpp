/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>
#include <stack>
// #include "dataStructure.h" // comment this before test

using namespace std;
// Solution 1: iteration
class Solution1
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        stack<int> s1, s2;
        ListNode *s1Helper = l1, *s2Helper = l2;
        while (l1)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }

        ListNode result(-1);
        ListNode *loop = &result;
        stack<int> reverseResult;
        int digit = 0;
        while (!s1.empty() || !s2.empty() || digit > 0)
        {
            digit += (s1.empty() ? 0 : s1.top()) + (s2.empty() ? 0 : s2.top());
            if (!s1.empty())
                s1.pop();
            if (!s2.empty())
                s2.pop();
            reverseResult.push(digit % 10);
            digit /= 10;
            // loop = loop->next;
        }

        while (!reverseResult.empty())
        {
            loop->next = new ListNode(reverseResult.top());
            reverseResult.pop();
            loop = loop->next;
        }

        return result.next;
    }
};

// Solution 2: recursive
//  ref: https://www.cnblogs.com/grandyang/p/6216480.html
//      use the idea of building a linked list reversely from the ref
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // find the len of two linked list
        int len1 = getLen(l1), len2 = getLen(l2);
// 
        // Q: why give the result a val of 1
        // A: use this to handle the last digit carry
        //   
        ListNode *result = new ListNode(1);
        result->next = (len1 > len2) ? addTwoNumbers(l1, l2, len1 - len2) : addTwoNumbers(l2, l1, len2 - len1);
        if(result->next->val > 9){
            result->next->val %= 10;
            return result;
        }
        return result->next;
    }

    // diff refs the difference of len between two linked list
    // PRINCIPLE: deal with the longer list first
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2, int diff)
    {
        if(!l1) return NULL;

        // find each digit from head to tail.
        // at this step, we did not consider the carry yet
        ListNode *currentDigit = (diff == 0) ? new ListNode(l1->val + l2->val) : new ListNode(l1->val);

        // now we nned to find the next digit result
        // call the recursive so the code after could add the carry to the previous node as the new digit was calculated
        ListNode *nextDigit = (diff == 0) ? addTwoNumbers(l1->next, l2->next, 0) : addTwoNumbers(l1->next, l2, diff - 1);

        // taking care the carry now
        if(nextDigit && nextDigit->val > 9){
            nextDigit->val %= 10;
            ++currentDigit->val;
        }

        // connect the next digit and current digit
        currentDigit->next = nextDigit;
        return currentDigit;
    }

    int getLen(ListNode* l){
        int count = 0;
        while(l){
            ++count;
            l = l->next;
        }
        return count;
    }
};
// @lc code=end
