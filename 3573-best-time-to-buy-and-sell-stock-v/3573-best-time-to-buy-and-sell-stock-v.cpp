class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        long long int n=prices.size();
        vector<vector<long long int>>dp(n,vector<long long int>(k+1,0));
        for(long long int j=1;j<=k;++j)
        {
            long long int buy=dp[0][j-1]-prices[0],sell=dp[0][j-1]+prices[0];
            for(long long int i=1;i<n;++i)
            {
                dp[i][j]=max<long long int>(dp[i-1][j],buy+prices[i]);
                buy=max<long long int>(buy,dp[i-1][j-1]-prices[i]);
                dp[i][j]=max<long long int>({dp[i][j],dp[i-1][j],sell-prices[i]});
                sell=max<long long int>(sell,dp[i-1][j-1]+prices[i]);
            }
        }
        return dp[n-1][k];
    }
};