#include <iostream>
#include <map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

// ref: http://bangbingsyb.blogspot.com/2014/11/leetcode-copy-list-with-random-pointer.html
// time: o(n) - go through list twice 2n -> n  
// space: o(n) - hash map
class HashMapSolution {
public:
    Node* copyRandomList(Node* head) {
        if (!head){
            return NULL;
        }
        
        // head of the deep copy linked list
        Node* copy = new Node(head->val, head->next, head->random);
        
        // two cursors to go through the list
        Node* current_node = copy;
        Node* next_node = head->next;
        
        // HashMap to store the passed node:
        // hash<origin_node, copy_node>
        map<Node*, Node*> memory;
        memory[head] = copy;
        
        // First loop: copy the next link first
        while(next_node){
            Node* temp = new Node(next_node->val, NULL, NULL);
            current_node->next = temp;
            memory[next_node] = temp; // add into hash
            current_node = current_node->next;
            next_node = next_node->next;
        }
        
        // Reset pointers back to the begining
        current_node = copy;
        next_node = head;
        
        // Second loop: copy the random link
        while(current_node){
            current_node->random = memory[next_node->random];
            current_node = current_node->next;
            next_node = next_node->next;
        }
        return copy;
    }
};


// not using hash map solution
// ref: https://www.youtube.com/watch?v=kGfsMookkzw
// time: o(n) - go through list three times 3n -> n  
// space: o(1)
class ConstantSpaceSolution{
    Node* copyRandomList(Node* head) {
        if (!head){
            return NULL;
        }
        Node* copy = head;
        
        // First, go through list and add a duplicated node after every original node.
        while(copy){
            Node* current = new Node(copy->val, NULL, NULL);
            current->next = copy->next;
            copy->next= current;
            copy = copy->next->next;
        }
        
        // Second, link the random links
        copy = head;
        while(copy){
            if (copy->random){
                copy->next->random = copy->random->next;
            }
            copy = copy->next->next;
        }
        
        // Third, extract the copied node.
        copy = head;
        // use this dummy node to hold the result
        Node* result = new Node(0,NULL, NULL);
        Node* copy_pointer = result;
        while (copy){
            // since each new node is behind the origin node, jump to next
            copy_pointer->next = copy->next;
            copy->next = copy->next->next;
            copy_pointer = copy_pointer->next;
            copy = copy->next;
        }
        return result->next;
    }
};