class Solution{
public:
    int maximumAmount(vector<vector<int>>&coins){
        int n=coins.size(),m=coins[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(3,INT_MIN)));
        for(int k=0;k<3;++k)
        {
            if(coins[n-1][m-1]>=0)dp[n-1][m-1][k]=coins[n-1][m-1];
            else dp[n-1][m-1][k]=(k>0?0:coins[n-1][m-1]);
        }
        for(int i=n-1;~i;--i)
        {
            for(int j=m-1;~j;--j)
            {
                if(i==n-1 && j==m-1)continue;
                for(int k=0;k<=2;++k)
                {
                    int ans=INT_MIN;
                    if(i+1<n)
                    {
                        if(coins[i][j]>=0)ans=max(ans,coins[i][j]+dp[i+1][j][k]);
                        else
                        {
                            ans=max(ans,coins[i][j]+dp[i+1][j][k]);
                            if(k>0)ans=max(ans,dp[i+1][j][k-1]);
                        }
                    }
                    if(j+1<m)
                    {
                        if(coins[i][j]>=0)ans=max(ans,coins[i][j]+dp[i][j+1][k]);
                        else
                        {
                            ans=max(ans,coins[i][j]+dp[i][j+1][k]);
                            if(k>0)ans=max(ans,dp[i][j+1][k-1]);
                        }
                    }
                    dp[i][j][k]=ans;
                }
            }
        }
        return dp[0][0][2];
    }
};