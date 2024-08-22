/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// Intuiton and Approach - 

// first i created a map that will map the current values to the nodes containing same values. 

// now we can simply travel through and mark the next and random pointer for all the nodes to the , actual nodes with next and random pointers. 

// Like mp[curr]->next - it implies the duplicate node we created with same value and change its next to mp[curr->next] means - its next should be equal the next of curr but we are pointing to duplicate value. 



class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node* , Node*>mp;

        Node* curr = head;
        while(curr){
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;
        while(curr){
            mp[curr]->next = mp[curr->next];
            mp[curr]->random = mp[curr->random];
            curr = curr->next;
        }
        return mp[head];
    }
};