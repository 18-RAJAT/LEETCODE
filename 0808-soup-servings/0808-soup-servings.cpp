class Solution {
public:
    double soupServings(int n) {
        if(n>=5000)
        {
            return 1.0;
        }
        n=(n+24)/25;
        double dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        dp[0][0]=0.5;
        for(int i=1;i<=n;++i)
        {
            dp[0][i]=1;
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                dp[i][j]=0.25*(dp[max(0,i-4)][j]+dp[max(0,i-3)][max(0,j-1)]+dp[max(0,i-2)][max(0,j-2)]+dp[max(0,i-1)][max(0,j-3)]);
            }
        }
        return dp[n][n];
    }
};