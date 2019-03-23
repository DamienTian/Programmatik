#ifndef _TREENODE_H
#define _TREENODE_H

#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL){};
};

/* Helper function that allocates a 
new node */
TreeNode* newNode(int data) 
{ 
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode)); 
    node->val = data; 
    node->left = node->right = NULL; 
    return (node); 
}

TreeNode* buildTree(int array[], int current_node, TreeNode *root, int n)
{
    // n: size of array
    if (current_node < n)
    {
        TreeNode* temp = newNode(array[current_node]);
        root = temp;

        // the left child of that node is at index (2*i + 1)
        root->left = buildTree(array, current_node * 2 + 1, root->left, n);

        // the right child is at index (2*i + 2) in the array
        root->right = buildTree(array, current_node * 2 + 2, root->right, n);
    }

    return root;
}

void inOrderTraversal(TreeNode* node)
{
    if (node != NULL)
    {
        inOrderTraversal(node->left);
        cout << node->val << " - ";
        inOrderTraversal(node->right);
    }
}
#endif
