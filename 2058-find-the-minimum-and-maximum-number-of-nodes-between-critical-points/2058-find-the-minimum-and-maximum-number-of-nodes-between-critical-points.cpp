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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int mini=INT_MAX,maxi=INT_MIN;
        int prev=0,check_p=INT_MIN,idx=0,pi=INT_MIN/2,fi=INT_MIN/2;
        bool flag=false;
        while(head)
        {
            if(idx==0)
            {
                prev=head->val;
                head=head->next;
                idx++;
                continue;
            }
            if((check_p!=INT_MIN) && ((head->val>prev && prev<check_p) || (head->val<prev && prev>check_p)))
            {
                if(!flag)
                {
                    fi=idx;
                    flag=true;
                }
                else
                {
                    mini=min(mini,idx-pi);
                    maxi=max(maxi,idx-fi);
                }
                pi=idx;
            }
            check_p=prev;
            prev=head->val;
            head=head->next;
            idx++;
        }
        vector<int>ans(2,-1);
        ans[0]=(mini!=INT_MAX)?mini:-1;
        ans[1]=(maxi!=INT_MIN)?maxi:-1;
        return ans;
    }
};