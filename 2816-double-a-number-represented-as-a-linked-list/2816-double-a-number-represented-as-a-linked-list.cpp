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
    ListNode* doubleIt(ListNode* head) {
      ListNode*prev=nullptr;
        ListNode*current=head;
        while(current!=nullptr)
        {
            ListNode*nextNode=current->next;
            current->next=prev;
            prev=current;
            current=nextNode;
        }
        ListNode*NHead=nullptr;
        ListNode*NTail=nullptr;
        int carry=0;
        while(prev!=nullptr)
        {
            int newVal=prev->val*2+carry;
            carry=newVal/10;
            newVal%=10;
            if(NHead==nullptr)
            {
                NHead=NTail=new ListNode(newVal);
            }
            else
            {
                NTail->next=new ListNode(newVal);
                NTail=NTail->next;
            }
            prev=prev->next;
        }
        if(carry>0)
        {
            NTail->next=new ListNode(carry);
        }
        ListNode*ans=nullptr;
        while(NHead!=nullptr)
        {
            ListNode*nextNode=NHead->next;
            NHead->next=ans;
            ans=NHead;
            NHead=nextNode;
        }
        return ans;
    }
};