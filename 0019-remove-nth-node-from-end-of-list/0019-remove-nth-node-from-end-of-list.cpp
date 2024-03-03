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
        vector<ListNode*>v;
        ListNode* temp=head;
        while(temp)
        {
            v.push_back(temp);
            temp=temp->next;
        }
        if(v.size()==n)
        {
            return head->next;
        }
        v[v.size()-n-1]->next=v[v.size()-n]->next;
        return head;
    }
};