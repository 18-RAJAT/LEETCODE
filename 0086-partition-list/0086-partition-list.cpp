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
    ListNode* partition(ListNode* head, int x) {
        ListNode n1(0),n2(0);
        ListNode*l1=&n1,*l2=&n2;
        while(head)
        {
            if(head->val<x)
            {
                l1->next=head;
                l1=l1->next;
            }
            else
            {
                l2->next=head;
                l2=l2->next;
            }
            head=head->next;
        }
        l2->next=NULL;
        l1->next=n2.next;
        return n1.next;
    }
};