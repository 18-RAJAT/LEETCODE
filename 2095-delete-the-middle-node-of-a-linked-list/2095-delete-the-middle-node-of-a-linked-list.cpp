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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==nullptr)
        {
            return nullptr;
        }
        ListNode*slow=head;
        ListNode*fast=head->next->next;
        
        // auto slow=head;
        // auto fast=head->next->next;
        
        while(fast!=nullptr and fast->next!=nullptr)
        {
            // if(fast->next->next!=NULL and fast->next->next->next!=NULL)
            // {
                    slow=slow->next;
                    fast=fast->next->next;
            // }
        }
        slow=slow->next=slow->next->next;
        return head;
    }
};