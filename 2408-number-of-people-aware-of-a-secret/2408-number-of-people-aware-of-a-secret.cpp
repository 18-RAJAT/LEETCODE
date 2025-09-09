class Solution {
public:
    int Mod=1000000007;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int>dp(forget,0);
        dp[0]=1;
        long long ans=1;
        for(int i=2;i<=n;++i)
        {
            ans-=dp[forget-1];
            long long res=0;
            for(int j=forget-1;j>0;--j)
            {
                dp[j]=dp[j-1];
                if(delay<=j)res=(res+dp[j])%Mod;
            }
            dp[0]=res,ans+=res,ans=ans;
        }
        return ans%Mod;
    }
};