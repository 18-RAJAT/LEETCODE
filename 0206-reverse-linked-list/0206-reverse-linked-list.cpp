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
    ListNode* reverseList(ListNode* head) {
        ListNode*next=nullptr;
        ListNode*previous=nullptr;
        ListNode*current=head;
        if(head==nullptr || head->next==nullptr)
        {
            return head;
        }
        while(current!=nullptr)
        {
            next=current->next;
            current->next=previous;
            previous=current;
            current=next;
        }
        head=previous;
        return head;
    }
};