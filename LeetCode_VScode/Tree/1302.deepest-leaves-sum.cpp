/*
 * @lc app=leetcode id=1302 lang=cpp
 *
 * [1302] Deepest Leaves Sum
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
// #include "dataStructure.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;

        vector<int> deepestNodes;
        int minDepth = 0;
        inOrdered(root, deepestNodes, 0, minDepth);

        int result = 0;
        for(int n : deepestNodes)
            result += n;

        return result;
    }

    void inOrdered(TreeNode* root, vector<int>& d, int depth, int& minDepth){
        if(!root) return;

        inOrdered(root->left, d, depth + 1, minDepth);
        if(minDepth < depth){
            minDepth = max(depth, minDepth);
            d.clear();
        }
        if(!root->left && !root->right && depth == minDepth) d.push_back(root->val);
        inOrdered(root->right, d, depth + 1, minDepth);
    }
};
// @lc code=end

