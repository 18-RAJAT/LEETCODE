class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>&fruits){
        int n=fruits.size(),m=fruits[0].size();
        vector dp(n,vector<int>(m,0));
        dp[0][m-1]=fruits[0][m-1];
        for(int i=1;i<n-1;++i)
        {
            for(int j=max(m-1-i,i+1);j<m;++j)
            {
                dp[i][j]=fruits[i][j];
                int x=dp[i-1][j];
                if(j>=1)x=max(x,dp[i-1][j-1]);
                if(j<m-1)x=max(x,dp[i-1][j+1]);
                dp[i][j]+=x;
            }
        }
        dp[n-1][0]=fruits[n-1][0];
        for(int j=1;j<m;++j)
        {
            for(int i=max(n-1-j,j+1);i<n;++i)
            {
                dp[i][j]=fruits[i][j];
                int x=dp[i][j-1];
                if(i>=1)x=max(x,dp[i-1][j-1]);
                if(i<n-1)x=max(x,dp[i+1][j-1]);
                dp[i][j]+=x;
            }
        }
        long long ans=0;
        for(int i=0;i<n;++i)ans+=fruits[i][i];
        ans+=dp[n-2][m-1],ans+=dp[n-1][m-2];
        return ans;
    }
};