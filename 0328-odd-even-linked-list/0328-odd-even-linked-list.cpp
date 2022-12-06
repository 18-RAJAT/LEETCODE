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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr or head->next==nullptr or head->next->next==nullptr)
        {
            return head;
        }
        ListNode*oddtail=head;
        ListNode*oddhead=head;
        ListNode*eventail=head->next;
        ListNode*evenhead=head->next;
        
        while(eventail!=nullptr and eventail->next!=nullptr)
        {
            oddtail->next = eventail->next;
            oddtail = eventail->next;
            
            eventail->next = oddtail->next;
            eventail = oddtail->next;
        }
        oddtail->next=evenhead;
        return oddhead;
    }
};