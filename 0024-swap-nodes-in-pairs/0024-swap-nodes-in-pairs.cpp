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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* prev=dummy;
        ListNode* curr=head;
        while(curr!=nullptr and curr->next!=nullptr)
        {
            ListNode* temp=curr->next;
            curr->next=temp->next;
            temp->next=curr;
            prev->next=temp;
            prev=curr;
            curr=curr->next;    
        }
        return dummy->next;
    }
};