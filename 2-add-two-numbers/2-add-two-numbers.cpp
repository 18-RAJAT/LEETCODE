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
        int sum1=l1->val;
        int sum2=l2->val;
        
        int total=sum1+sum2;
        
        int current=total/10;
        
        //l1 node
        l1->val=total%10;
        //initialy point l1
        ListNode* head=l1;
        
        // if(l1->next==NULL and l2->next==NULL){return NULL;}
        
        while(l1->next!=NULL and l2->next!=NULL)
        {
            total=l1->next->val+l2->next->val+current;
            current=total/10;
            
            l1->next->val=total%10;
            l1=l1->next;l2=l2->next;
        }
        
        if(l1->next==NULL){l1->next=l2->next;}
        
        while(l1->next!=NULL)
        {
            total=l1->next->val+current;current=total/10;
            //9999+0000=9999
            l1->next->val=total%10;
            //value 1 get then move next.
            l1=l1->next;
        }
        // if(current!=0){return NULL;}
        // cout<<'0';
        if(current!=0){l1->next=new ListNode(current);}
        // cout<<'1';
        // cout<<head;
        return head;
    }
};