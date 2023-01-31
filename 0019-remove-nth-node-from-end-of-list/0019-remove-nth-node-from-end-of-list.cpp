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
        ListNode*temp=head;
        int length=0;
        while(temp!=nullptr)
        {
            length++;
            temp=temp->next;
        }
        if(length==n)//if we have to delete the first node 
        {
            return head->next;
        }
        temp=head;
        //we have to delete the node after (len-n-1)th node
        int dec=length-n-1;
        for(int i=0;i<dec;++i)
        {
            temp=temp->next;
        }
        temp->next=temp->next->next;//delete the node
        return head;
    }
};
//Time complexity O(n) and Space complexity O(1)