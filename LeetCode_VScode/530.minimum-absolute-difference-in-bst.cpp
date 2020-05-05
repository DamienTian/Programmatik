/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
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
#include <algorithm>

using namespace std;

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution
{
public:
    int getMinimumDifference(TreeNode *root)
    {
        inOrder(root);
        return result;
    }

private:
    int result = INT_MAX;
    TreeNode* previousNode = nullptr;

    void inOrder(TreeNode* root){
        if(!root)   return;
        inOrder(root->left);
        if(previousNode != nullptr){
            result = min(result, abs(root->val - previousNode->val));
        }
        previousNode = root;
        inOrder(root->right);
    }
};

// @lc code=end
