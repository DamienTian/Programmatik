#include "TreeNode.h"
#include <math.h>

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q){
            return true;
        }
        
        else if ((p && !q) || (q && !p)){
            return false;
        }
        
        else{
            if (p->val != q->val){
                return false;
            }
        }
        
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main(){

    int a1[3] = {1,2,3};
    int a2[3] = {1,2,3};

    int n = sizeof(a1)/sizeof(a1[0]);

    TreeNode* t1 = buildTree(a1, 0, t1, n);
    TreeNode* t2 = buildTree(a2, 0, t2, n);

    inOrderTraversal(t1);
    cout << endl;
    inOrderTraversal(t2);
    cout << endl;

    Solution s;
    cout << s.isSameTree(t1, t2) <<endl;

    return 0;
}