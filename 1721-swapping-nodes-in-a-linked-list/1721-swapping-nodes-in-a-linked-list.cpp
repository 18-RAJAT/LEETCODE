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
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode* x = head;
        ListNode* y = head;
        ListNode* t = head;
        
        // Until we reach k-th node from beginning
        
        while(k > 1)
        {
            x = x->next;
            t = t->next;
            
            k--;
        }
        
        // Until pointer t reach last need 
        while(t->next)
        {
            y = y->next;
            t = t->next;
            
        }
        
        //swap value at the both nodes
        int temp = x->val;
        x->val = y->val;
        y->val = temp;
        
        return head;
    }
};