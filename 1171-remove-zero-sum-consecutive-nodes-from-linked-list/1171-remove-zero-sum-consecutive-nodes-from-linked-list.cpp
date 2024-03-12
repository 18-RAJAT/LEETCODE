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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        unordered_map<int,ListNode*> m;
        int sum=0;
        for(ListNode* i=dummy;i!=nullptr;i=i->next)
        {
            sum+=i->val;
            m[sum]=i;
        }
        sum=0;
        for(ListNode* i=dummy;i!=nullptr;i=i->next)
        {
            sum+=i->val;
            i->next=m[sum]->next;
        }
        return dummy->next;
    }
};