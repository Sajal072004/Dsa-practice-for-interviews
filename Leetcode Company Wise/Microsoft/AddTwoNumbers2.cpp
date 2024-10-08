/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


// Intuiton and approach -

// Simple keep a carry for next number and keep adding the values and add new nodes. 
// At last check if carry still exists just add a node with the value 1
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newHead = new ListNode(); int carry = 0;
        ListNode*temp = newHead;
        while(l1 && l2){
            ListNode* newNode = new ListNode( (l1->val + l2->val + carry)%10 );
            temp->next = newNode;
            temp = newNode;
            carry = (l1->val + l2->val + carry)/10;
            l1 = l1->next; l2 = l2->next;
        }

        while(l1){
            ListNode* newNode = new ListNode((l1->val + carry)%10 );
            temp->next = newNode;
            temp = newNode;
            carry = (l1->val + carry)/10;
            l1 = l1->next;
        }

        while(l2){
            ListNode* newNode = new ListNode((l2->val + carry)%10);
            temp->next = newNode;
            temp = newNode;
            carry = (l2->val + carry)/10;
            l2 = l2->next;
        }
        if(carry){
            ListNode* newNode = new ListNode(1);
            temp->next = newNode;
        }
        return newHead->next;
    }
};