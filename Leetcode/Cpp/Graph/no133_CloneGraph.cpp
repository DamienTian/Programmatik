// ref: https://www.cnblogs.com/grandyang/p/4267628.html
#include "../includes.h"

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

// Solution 1: DFS
// Time: O(n), Space: O(n)  [未被验证]

class DFSSolution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> hash;
        return dfs(node, hash);
    }
    
    // use DFS to go through all the nodes 
    Node* dfs(Node* node, unordered_map<Node*, Node*>& hashMap){
        if(!node){
            return NULL;
        }
        
        // if we visited the node, we just return the corresponding copy node
        if(hashMap.count(node)){
            return hashMap[node];
        }
        
        // if not, we created a deep copy, but leave the neighbors as NULL for now
        Node* copy = new Node(node->val);
        // stores the corresponding node into the hash    
        hashMap[node] = copy;
        
        for (Node* n: node->neighbors){
            copy->neighbors.push_back(dfs(n, hashMap));
        }
        
        return copy;
    }
};

// Solution 2: BFS
//  Time: O(n), Space: O(2n) -> O(n)    [未被验证]
class BFSSolution {
public:
    Node* cloneGraph(Node* node) {
        // hash table to stores the Node -> Copied Node
        unordered_map<Node*, Node*> hash;
        
        // The queue to stores all unvisited node
        queue<Node*> q;
        q.push(node);
        
        // The deep copy graph
        Node* copy = new Node(node->val);
        // Store the node into the hash
        hash[node] = copy;
        
        while(!q.empty()){
            // the current visit node
            Node* curr = q.front();
            q.pop();    // pop 
            
            // Loop through all neighbors (BFS)
            for (Node* n : curr->neighbors){
                // if we cannot find the node, add them into the hash
                if(!hash.count(n)){
                    hash[n] = new Node(n->val);
                    q.push(n);
                }
                
                // link it's neighbors to it's deep copy
                hash[curr]->neighbors.push_back(hash[n]);
            }
        }
        
        return copy;
    }
};