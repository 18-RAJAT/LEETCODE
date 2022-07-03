class Solution {
public:
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) {
         
        vector<vector<int>> ans(n, vector<int> (m, -1));
        ListNode* tmp = head;
        int t = 0, l = 0, b = n-1, r = m-1;
        while(1)
        {
            for(int i=l;i<=r;i++)
            {
                ans[t][i] = tmp->val;
                tmp = tmp->next;
                if(tmp == NULL)
                    break;
            }
            t++;
            if(tmp == NULL)
                break;
            
            for(int i = t;i<=b;i++)
            {
                ans[i][r] = tmp->val;
                tmp = tmp->next;
                if(tmp == NULL)
                    break;
            }
            r--;
            if(tmp == NULL)
                break;
            
            for(int i = r;i>=l;i--)
            {
                ans[b][i] = tmp->val;
                tmp = tmp->next;
                if(tmp == NULL)
                    break;
            }
            b--;
            if(tmp == NULL)
                break;
            
            for(int i = b;i>=t;i--)
            {
                ans[i][l] = tmp->val;
                tmp = tmp->next;
                if(tmp == NULL)
                    break;
            }
            l++;
            if(tmp == NULL)
                break;
        }
        return ans;
    }
};