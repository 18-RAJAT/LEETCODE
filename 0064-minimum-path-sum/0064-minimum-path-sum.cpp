class Solution {
public:
    // int rec(vector<vector<int>>grid,int row,int col)
    // {
    //     int n=grid.size();
    //     int m=grid[0].size();
    // }
    int minPathSum(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        // int up,left,right,down;
        
          //vector<int>current(n),previous(n);
         // int previous[n];
         // memset(previous,0,sizeof(previous));
         // vector<vector<int>>dp(n,vector<int>(m));
        // int current[n];
        
        int dp[n][m];
        dp[0][0]=grid[0][0];
        // memset(dp,0,sizeof(dp));
        for(int i=1;i<n;++i)
        // {
        // {
            dp[i][0]=dp[i-1][0]+grid[i][0];
        // }
        for(int j=1;j<m;++j)
        // {
        // {
            dp[0][j]=dp[0][j-1]+grid[0][j];
        // }
        // cout<<dp[i][j]<<" ";
        // cout<<"\n";
        // }}
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }
        
        for(int i=1;i<n;++i)
        {
            for(int j=1;j<m;++j)
            {
                int mn=min(dp[i-1][j],dp[i][j-1]);
                dp[i][j]=mn+grid[i][j];
            }
        }
        return dp[n-1][m-1];
    }
};