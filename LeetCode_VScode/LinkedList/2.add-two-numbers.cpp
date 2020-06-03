/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start

// Definition for singly-linked list.
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

#include <iostream>
// #include "dataStructure.h" // comment this before test and submit

using namespace std;

// ref: https://zxi.mytechroad.com/blog/list/leetcode-2-add-two-numbers/
//      https://www.cnblogs.com/grandyang/p/4129891.html 

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // 为了避免两个输入链表同时为空，我们建立一个 dummy 结点，(在这里是 result)
        // 将两个结点相加生成的新结点按顺序加到 dummy 结点之后，
        // 由于 result 结点本身不能变，所以用一个指针 tail 来指向新链表的最后一个结点。
        ListNode *result = new ListNode(0);
        ListNode *tail;
        tail = result;
        // use this to store the next digit
        int next = 0;
        while(l1 || l2 || next){
            next += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            l1 = (l1 ? l1->next : nullptr);
            l2 = (l2 ? l2->next : nullptr);
            // 之所以要建立一个新的节点，是为了防止跳到下一个节点时 tail = nullptr
            tail->next = new ListNode(next % 10);
            next /= 10;
            tail = tail->next;
        }
        return result->next;
    }
};
// @lc code=end
