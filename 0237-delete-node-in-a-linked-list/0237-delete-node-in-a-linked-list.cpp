/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp=node->next;
        if(node==nullptr and node->next==nullptr)
        {
            delete node;
        }
        swap(node->val,node->next->val);
        node->next=node->next->next;
        
        delete temp;
    }
};