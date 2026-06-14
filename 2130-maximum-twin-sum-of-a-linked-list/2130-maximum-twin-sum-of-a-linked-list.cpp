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
    int pairSum(ListNode* head) {
        vector<int>storeEle;
        int maxi(0);
        while(head)
        {
            storeEle.push_back(head->val);
            head=head->next;
        }
        for(int i=0;i<storeEle.size()/2;++i)
        {
            maxi=max<int>(maxi,storeEle[i]+storeEle[storeEle.size()-i-1]);
        }
        return maxi;
    }
};