#include "../includes.h"

 // Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

// Solution 1
// ref: https://www.geeksforgeeks.org/understanding-nullptr-c/
// Time: O(n) Space O(n)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // result
        vector<int> result;

        // the stack use to stores the node, pop the left node
        stack<TreeNode*> stack;

        // a tree node that is used for tranversing the tree
        TreeNode* node = root;

        // Keep traversing left
        while(!stack.empty() || node != nullptr){
            if (node != nullptr){
                stack.push(node);
                node = node->left;
            }

            // When node reach the bottom of the left
            else{
                node = stack.top();
                stack.pop();
                result.push_back(node->val);

                // check the right node under the same parent.
                // if node is NULL, which means no right node,
                // node becomes the parent (node = s.pop())
                node = node->right;
            }
        }

        return result;
    }
};