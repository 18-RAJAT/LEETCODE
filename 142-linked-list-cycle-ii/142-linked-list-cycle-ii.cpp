/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(head == NULL){return NULL;}
        ListNode* slow=head,*fast=head;
            while(fast!=NULL and fast->next!=NULL)
            {
                    fast=fast->next->next;
                    slow=slow->next;
            if(slow==fast)
            {
                   slow=head;
                  while(slow!=fast)
                  {fast = fast->next;slow = slow->next;}return fast;
            }
          }
            return NULL;
    }
};
