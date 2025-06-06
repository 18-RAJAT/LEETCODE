class Solution {
public:
    int numTilings(int n) {
        vector<int>dp(n+5,0);
        int mod=1000000007;
        dp[1]=1;
        dp[2]=2;
        dp[3]=5;
        for(int i=4;i<=n;i++)
        {
            dp[i]=((2*((dp[i-1])%mod))%mod+(dp[i-3])%mod)%(mod);
        }
        return dp[n];
    }
};