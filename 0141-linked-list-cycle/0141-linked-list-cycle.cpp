/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        function<ListNode*(ListNode*)>floyd_Warshall=[&](ListNode*head)->ListNode*
        {
            ListNode*slow=head;
            ListNode*fast=head;
            while(fast!=nullptr && fast->next!=nullptr)
            {
                slow=slow->next;
                fast=fast->next->next;
                if(slow==fast)
                {
                    return slow;
                }
            }
            return nullptr;
        };
        ListNode*cycle=floyd_Warshall(head);//returns the node where cycle starts
        return ((cycle!=nullptr)?true:false);
    }
};