/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
// #include "dataStructure.h"

// Solutions Ref: https://www.cnblogs.com/grandyang/p/4441680.html
// Solution 1: iteration
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head)   return NULL;
        if(!head->next) return head;

        ListNode* dummy = new ListNode(-1);
        ListNode* loopDummy = dummy;
        dummy->next = head;
 
        // looping while there are at least two node can be swap
        while(loopDummy->next && loopDummy->next->next){
            // 0) assign the node that behind and it will be swaped to the front 
            ListNode* secondNode = loopDummy->next->next;
            // 1) connect the first node's next to the second node's next
            loopDummy->next->next = secondNode->next;
            // 2) then connect the second node's next to the first node
            secondNode->next = loopDummy->next;
            // 3) connect the dummy head OR last node of swaped list to the second node
            //    second node now become the first node
            loopDummy->next = secondNode;
            // 4) move the loop dummy tail to the current second node and start the next round swap
            loopDummy = secondNode->next;
        }

        return dummy->next;
    }
};

// TODO: write the recursive solution for review
// HINT: 递归的写法就更简洁了，实际上利用了回溯的思想，递归遍历到链表末尾，然后先交换末尾两个，然后依次往前交换：

// @lc code=end

