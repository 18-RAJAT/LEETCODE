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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL){return NULL;}
        ListNode*ans=new ListNode(0,head);
        ListNode*prev=ans;
        
        for(int i=0;i<left-1;++i)prev=prev->next;
        ListNode* curr=prev->next;
        
        // int tp=left++;
        while(left++<right)
        {
            ListNode*temp=curr->next;//cout<<'1';
            curr->next=temp->next;//cout<<'2';
            temp->next=prev->next;//cout<<'3';
            prev->next=temp;
        }
        // cout<<ans;
        return ans->next;
    }
};