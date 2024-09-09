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
    vector<vector<int>> spiralMatrix(int m,int n,ListNode* head) {
        vector<vector<int>>ans(m,vector<int>(n,-1));
        int i=0,j=0,k=0;
        int dir[5]={0,1,0,-1,0};
        do
        {
            ans[i][j]=head->val;
            head=head->next;
            if(!head) break;
            do
            {
                int x=i+dir[k],y=j+dir[k+1];
                if(x>=0 && x<m && y>=0 && y<n && ans[x][y]==-1)
                {
                    i=x;
                    j=y;
                    break;
                }
                k=(k+1)%4;
            }while(true);
        }while(head);
        
        return ans;
    }
};