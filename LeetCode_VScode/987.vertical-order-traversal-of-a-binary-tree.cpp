/*
 * @lc app=leetcode id=987 lang=cpp
 *
 * [987] Vertical Order Traversal of a Binary Tree
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
#include <map>
#include <set>
#include <algorithm>

using namespace std;

// Solution 1: map + set + tranversal
// ref: https://zxi.mytechroad.com/blog/tree/leetcode-987-vertical-order-traversal-of-a-binary-tree/

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root)   return {};

        // Q: why use set? A: keep num sorted
        map<pair<int, int>, set<int>> levelRecorder;
        // mark the min and max x 
        int minX = INT_MAX;
        int maxX = INT_MIN;

        preorder(root, 0, 0, minX, maxX, levelRecorder);

        // build the result before return it
        vector<vector<int>> result(maxX - minX + 1);

        for(const auto& level : levelRecorder){
            int l = level.first.first - minX;
            result[l].insert(end(result[l]), begin(level.second), end(level.second));
            // sort(result[l].begin(), result[l].end());
        }

        return result;
    }

private:
    void preorder(TreeNode* root, int x, int y, int& minX, int& maxX, map<pair<int, int>, set<int>>& levelRecorder){
        if(!root)   return;

        minX = min(minX, x);
        maxX = max(maxX, x);
        levelRecorder[{x,y}].insert(root->val);
        preorder(root->left, x - 1, y + 1, minX, maxX, levelRecorder);
        preorder(root->right, x + 1, y + 1, minX, maxX, levelRecorder);
    }
};

// @lc code=end

