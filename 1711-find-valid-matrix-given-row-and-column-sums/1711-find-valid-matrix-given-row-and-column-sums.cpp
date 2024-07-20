class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& row, vector<int>& col) {
        int n=row.size(),m=col.size();
        vector<vector<int>>ans(n,vector<int>(m));
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                int mn=min(row[i],col[j]);
                row[i]-=mn;
                col[j]-=mn;
                ans[i][j]+=mn;
            }
        }
        return ans;
    }
};