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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum1=l1->val,sum2=l2->val;
        int total=sum1+sum2,current=total/10;
        l1->val=total%10;
        ListNode* head=l1;
        while(l1->next!=nullptr && l2->next!=nullptr)
        {
            total=l1->next->val+l2->next->val+current;
            current=total/10;
            
            l1->next->val=total%10;
            l1=l1->next;l2=l2->next;
        }
        
        if(l1->next==nullptr){l1->next=l2->next;}
        
        while(l1->next!=nullptr)
        {
            total=l1->next->val+current;current=total/10;
            l1->next->val=total%10;
            l1=l1->next;
        }
        if(current!=0){l1->next=new ListNode(current);}
        return head;
    }
};