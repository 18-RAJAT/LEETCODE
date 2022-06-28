class Solution {
public:
    int countHousePlacements(int n) {
        long modulo=1000000007;
        vector<long> dp(n+5, 0);
        dp[1]=2,dp[2]=3;
        for(int i=3; i<=n; i++){
            dp[i]=(dp[i-1]+dp[i-2])%modulo;
        }
        return (dp[n]*dp[n])%modulo;
    }
};