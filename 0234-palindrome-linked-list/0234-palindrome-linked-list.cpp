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
        ListNode*temp=head;
        while(temp!=NULL)
        {
            a.push_back(temp->val);
            temp=temp->next;
        }
        int start=0,end=a.size()-1;
        while(start<end)
        {
            if(a[start]!=a[end])
            {
                return false;
            }
            start++;end--;
        }
        return true;
    }
};