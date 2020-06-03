/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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

// Solution: Morris Traversal
//  ref: https://www.cnblogs.com/grandyang/p/4297300.html
//      https://www.cnblogs.com/AnnieKim/archive/2013/06/15/MorrisTraversal.html 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)   return {};

        vector<int> result;
        TreeNode *cur = root, *pre = nullptr;
        while(cur){
            if(!cur->left){
                result.push_back(cur->val);
                cur = cur->right;
            }

            else{
                pre = cur->left;

                while(pre->right != nullptr && pre->right != cur)
                    pre = pre->right;
                
                if(pre->right == nullptr){
                    pre->right = cur;
                    cur = cur->left;
                }

                else if(pre->right == cur){
                    pre->right = nullptr;
                    result.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }

        return result;
    }
};
// @lc code=end

