#include "../includes.h"
 
 // Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 

// ref: http://zxi.mytechroad.com/blog/tree/leetcode-98-validate-binary-search-tree/

// Solution 1: use LLONG_MIN and LLONG_MAX to define the boundaries
//  Time: O(n)  Space: O(h) h: height of the tree
class LLONGSolution {
public:
    bool isValidBST(TreeNode* root) {
        /* 
           Q: why use LLONG_MIN and LLONG_MAX to define the boundaries?
           A: becasue the tree node's val is integer. we need to make sure the program can 
              runs on 64 bits, so we use the LLONG_MIN and LLONG_MAX to set the boundaries.
        */
        return helper(root, LLONG_MIN, LLONG_MAX);
    }
    
    // if we use LLONG_MIN and LLONG_MAX to set boundaries, we also 
    //  need to set the min and max inputs as type 'long'.
    // BUT, if we use the nullptr, we can set the parameters as int*
    bool helper(TreeNode* root, long min, long max){
        if (root == nullptr){
            return true;
        }
        
        // need to consider the equal case:
        //      ex. [1,1]
        if (root->val <= min || root->val >= max){
            return false;
        }
        return helper(root->left, min, root->val) && helper(root->right, root->val, max);
    }
};

// Solution 2: use nullptr to set the boundaries
//  Time: O(n)  Space: O(h) h: height of the tree
class NullptrSolution {
public:
    bool isValidBST(TreeNode* root) {
        // nullptr is infinity
        return isValidBST(root, nullptr, nullptr);
    }
private:
    bool isValidBST(TreeNode* root, int* min_val, int* max_val) {
        if (!root) {
            return true;
        }
        // use "min_val && root->val" to detact if the min_val is empty (NULL)
        if ((min_val && root->val <= *min_val) 
          ||(max_val && root->val >= *max_val)){
            return false;
        }  
        
        // use "&root->val" to give the address of the val 
        return isValidBST(root->left, min_val, &root->val)
            && isValidBST(root->right, &root->val, max_val);
    }
};

// Solution 3: use the property of the BST (in-order tranversal of a valid BST is sorted)
//  Time: O(n)  Space: O(h)   the recursive call takes space in stack
class SortSolution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        // this line of code is to recursively call the root->left
        // the return statement is unlikely by called because the previous if statementis always true.
        if(!isValidBST(root->left)){
            return false;
        }
        
        // since the in order tranversal of BST is sorted for small to large,
        //  the value of the new root value should not be smaller than the previous value.
        //  if not, return false
        if (previous != nullptr && previous->val >= root->val){
            return false;
        }
        
        previous = root;
        
        return isValidBST(root->right);
    }
    
    // use this to stores the previous in-order tranversal value
    TreeNode* previous = nullptr;
};

int main(){
    // so if(false) statement won't print any shit
    if(false){
        cout << "WTF" << endl;
    }
}