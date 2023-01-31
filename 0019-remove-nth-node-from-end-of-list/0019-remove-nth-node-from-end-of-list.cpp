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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //time complexity O(n) and space complexity O(1)
        ListNode* temp=head;
        int len=0;
        while(temp!=NULL)
        {
            // cout<<temp->val<<" ";
            len++;
            temp=temp->next;
        }
        if(len==n)//if we have to delete the first node 
        {
            return head->next;
        }
        temp=head;//
        for(int i=0;i<len-n-1;i++)//we have to delete the node after (len-n-1)th node
        {
            temp=temp->next;
        }
        temp->next=temp->next->next;//deleting the node a
        return head;      
    }
};