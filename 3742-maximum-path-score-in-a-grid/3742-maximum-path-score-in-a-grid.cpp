class Solution{
public:
    int n,m;
    vector<vector<vector<int>>>dp;
    vector<vector<int>>dir{{0,1},{1,0}};
    int solve(vector<vector<int>>& grid,int k,int i,int j)
    {
        if(i<0 || i>=n || j<0 || j>=m)return INT_MIN;
        int cost=grid[i][j]==0?0:1;
        if(k<cost)return INT_MIN;
        k-=cost;
        if(i==n-1 && j==m-1)return grid[i][j];
        if(~dp[i][j][k])return dp[i][j][k];
        int ans=INT_MIN;
        for(auto& it:dir)
        {
            int x=i+it[0],y=j+it[1];
            ans=max(ans,solve(grid,k,x,y));
        }
        if(ans==INT_MIN)return dp[i][j][k]=INT_MIN;
        return dp[i][j][k]=ans+grid[i][j];
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();
        dp.assign(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        int ans=solve(grid,k,0,0);
        return ans==INT_MIN?-1:ans;
    }
};