class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int sz=high+low;
        vector<int>dp(sz,0);
        
        dp.resize(sz+1);
        dp[0]=1;
        int ans=0;
        for(int i=0;i<=high;++i)
        {
            dp[i+zero]=(dp[i]+dp[i+zero])%1000000007;
            dp[i+one]=(dp[i]+dp[i+one])%1000000007;
            if(i>=low and i<=high)
            {
                ans=(ans+dp[i])%1000000007;
            }
        }
        return ans;
    }
};