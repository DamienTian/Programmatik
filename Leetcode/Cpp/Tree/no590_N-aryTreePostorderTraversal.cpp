#include "../includes.h"

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// ref: https://www.cnblogs.com/grandyang/p/9881420.html
// Solution 1: recursive
// Time: O(n)   Space: O(n)

class RecursiveSolution {
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        // a recursive function which tranverse all childrens
        helper(root, result);
        return result;
    }
    
    void helper(Node* node, vector<int>& result){
        // no child OR no more child
        if(node == nullptr){
            return;
        }
        for (Node* child: node->children){
            helper(child, result);
        }
        
        // when tranverse all the child (no more child)
        // add the node into the result
        result.push_back(node->val);
    }
};

// Solution 2: iteration
//  Time: O(n)  Space: O(n)

// Q: Why this solution is slow?
// A (unverified): Because the vector::insert is slow.
//      ref: https://www.hackerearth.com/practice/notes/standard-template-library/
//      insert(): Inserts new elements into the vector at a particular position. 
//      time complexity is O(N + M) where N is the number of elements inserted and M is the 
//      number of the elements moved.

class IterationSolution {
public:
    vector<int> postorder(Node* root) {
        // the return result
        vector<int> result;
        
        if(root == nullptr){
            return result;
        }
        
        // stack stores all the childs
        stack<Node*> stack;
        stack.push(root);
        
        while(!stack.empty()){
            Node* current = stack.top();
            stack.pop();
            result.insert(result.begin(), current->val);
            
            for (Node* child : current->children){
                if(child != nullptr){
                    stack.push(child);
                }
            }
        }
        return result;
    }
};