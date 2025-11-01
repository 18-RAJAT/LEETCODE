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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        int n=nums.size();
        unordered_set<int>st;
        for(int i=0;i<n;++i)st.insert(nums[i]);
        ListNode* a=new ListNode(NULL);
        ListNode* temp=a;
        while(head!=NULL)
        {
            if(st.find(head->val)==st.end())
            {
                temp->next=head;
                temp=temp->next;
            }
            head=head->next;
        }
        temp->next=head;
        return a->next;
    }
};