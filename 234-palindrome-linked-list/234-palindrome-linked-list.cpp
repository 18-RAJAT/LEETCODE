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
    bool isPalindrome(ListNode* head) {
        vector<int>a;
        ListNode*tp=head;
        while(tp!=NULL)
        {
            a.push_back(tp->val);tp=tp->next;
        }
        int start=0,end=a.size()-1;
        while(start<end)
        {
            if(a[start]!=a[end])return 0;
                start++;end--;
        }
        return 1;
    }
};