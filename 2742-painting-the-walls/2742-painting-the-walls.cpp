class Solution {
public:
    int dp[505][505];
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n=cost.size();
        for(int i=0;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                dp[i][j]=INT_MAX;
            }
        }
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<=n;++j)
            {
                int &ans=dp[i][j];
                // if(~ans)
                // {
                //     return ans;
                // }
                if(ans==INT_MAX)
                {
                    continue;
                }
                dp[i+1][j]=min(dp[i+1][j],ans);
                dp[i+1][min(n,j+time[i]+1)]=min(dp[i+1][min(n,j+time[i]+1)],ans+cost[i]);
            }
        }
        return dp[n][n];
    }
};