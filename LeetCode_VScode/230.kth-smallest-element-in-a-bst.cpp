/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
 */

// @lc code=start

#include <stack>

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

// https://www.cnblogs.com/grandyang/p/4620012.html

// Solution 1: iteration
// class Solution
// {
// public:
//     int kthSmallest(TreeNode *root, int k)
//     {
//         // use a temp TreeNode to inorder tranvers tree
//         TreeNode* p = root;
//         // use a stack to inorder tranvers the tree;
//         stack<TreeNode*> s;

//         while(p || !s.empty()){
//             // travel left node until reach the bottom
//             while(p){
//                 s.push(p);
//                 p = p->left;
//             }

//             // pop the top node, which is the leftest node of tree of subtree
//             p = s.top();
//             s.pop();
//             // deduct k and check the index
//             k -= 1;
//             if(k == 0)  return p->val;

//             // tranvers right
//             p = p->right;
//         }

//         return -1;
//     }
// };

//Solution 2: recursive
class Solution
{
public:
    int kthSmallest(TreeNode* root, int k)
    {
        return inOrder(root, k);
    }

private:
    int inOrder(TreeNode* root, int& k){
        if(!root)   return -1;
        int val = inOrder(root->left, k);
        // NOTE: 这两行分别追溯根的左子树节点和此节点，
        //      若都没有return, 则进入右子树
        // ----------------------------------
        if(k == 0)  return val;
        if(--k == 0)  return root->val;
        // ----------------------------------
        // --k;
        return inOrder(root->right, k);
    }
};

// @lc code=end
