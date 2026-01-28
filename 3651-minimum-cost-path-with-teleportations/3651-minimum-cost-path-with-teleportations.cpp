class Solution {
public:
    void sol(vector<vector<int>>& dp,vector<vector<int>>& grid)
    {
        int n=grid.size(),m=grid[0].size();
        dp[0][0]=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(i>=1)dp[i][j]=min(dp[i][j],dp[i-1][j]+grid[i][j]);
                if(j>=1)dp[i][j]=min(dp[i][j],dp[i][j-1]+grid[i][j]);
            }
        }
    }
    int minCost(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,1e9)),cur(n,vector<int>(m,1e9));
        vector<int>ar;
        unordered_map<int,int>mp;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                ar.push_back(grid[i][j]);
            }
        }
        stable_sort(ar.begin(),ar.end());
        ar.erase(unique(ar.begin(),ar.end()),ar.end());
        int sz=ar.size();
        for(int i=0;i<sz;++i)mp[ar[i]]=i;
        sol(dp,grid);
        int ans=dp[n-1][m-1];
        for(int x=1;x<=k;++x)
        {
            vector<int>res(sz,1e9);
            cur.assign(n,vector<int>(m,1e9));
            for(int i=0;i<n;++i)
            {
                for(int j=0;j<m;++j)
                {
                    res[mp[grid[i][j]]]=min(res[mp[grid[i][j]]],dp[i][j]);
                }
            }
            for(int i=sz-2;~i;--i)
            {
                res[i]=min(res[i],res[i+1]);
            }
            for(int i=0;i<n;++i)
            {
                for(int j=0;j<m;++j)
                {
                    cur[i][j]=min(dp[i][j],res[mp[grid[i][j]]]);
                }
            }
            sol(cur,grid);
            dp=move(cur);
            ans=dp[n-1][m-1];
        }
        return ans;
    }
};