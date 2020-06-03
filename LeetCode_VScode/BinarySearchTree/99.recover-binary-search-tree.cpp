/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <iostream>
#include <vector>
#include <utility>
// #include "dataStructure.h"

using namespace std;

// ref: https://www.cnblogs.com/grandyang/p/4298069.html
class Solution1
{
public:
    void recoverTree(TreeNode *root)
    {
        inOrder(root);
        swap(first->val, second->val);
    }

private:
    // record two node that is swap by mistake
    TreeNode *first = nullptr, *second = nullptr;
    // the previous node of inOrder tranversal
    TreeNode *pre = nullptr;

    void inOrder(TreeNode *root)
    {
        if (!root)
            return;
        inOrder(root->left);
        if (!pre)
            pre = root;
        else
        {
            if (pre->val > root->val)
            {
                if (!first)
                    first = pre;
                second = root;
            }
            pre = root;
        }
        inOrder(root->right);
    }
};

// Solution 2: Morris Inordered Traversal
//  add ref: https://www.cnblogs.com/AnnieKim/archive/2013/06/15/MorrisTraversal.html
//  Space Complexity: O(n)
class Solution
{
public:
    void recoverTree(TreeNode *root)
    {
        // current, previous node for Morris traversal
        // parent node is used for traverse the tree, pre stores previous node
        TreeNode *cur = root, *pre = nullptr, *parent = nullptr;
        // mark first and second misswap node 
        // NOTE: must be set to NULL or it will cause memory leak
        TreeNode *first = nullptr, *second = nullptr;

        while(cur){
            // search left side first
            if(cur->left){
                parent = cur->left;
                while(parent->right && parent->right != cur)
                    parent = parent->right;
                
                if(!parent->right){
                    parent->right = cur;
                    cur = cur->left;
                    continue;   // jump out the loop to search new left node
                }
                else if(parent->right == cur)
                    parent->right = nullptr;
            }

            // reach the end of the left branch
            // detect if a mistake swap exist
            if(pre && pre->val > cur->val){
                if(!first)  first = pre;
                second = cur;
            }

            // keep searching in Morris inorder traversal
            pre = cur;
            cur = cur->right;
        }

        swap(first->val, second->val);
    }
};
// @lc code=end