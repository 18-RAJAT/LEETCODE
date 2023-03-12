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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode*head=new ListNode(0);
        ListNode*temp=head;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        for(auto x:lists)
        {
            if(x)
            {
                pq.push({x->val,x});
            }
        }
        while(not pq.empty())
        {
            auto x=pq.top();
            pq.pop();
            temp->next=x.second;
            temp=temp->next;
            if(x.second->next)
            {
                pq.push({x.second->next->val,x.second->next});
            }
        }
        return head->next;
    }
};