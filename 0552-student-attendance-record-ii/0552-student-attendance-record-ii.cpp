class Solution {
public:
    int checkRecord(int n) {
        vector<long long>dp(n+1);
        int op1=0,op2=0,nop1=1,nop2=0;
        dp[0]=1;
        for(int i=1;i<=n;++i)
        {
            long long take,leave;
            take=(nop1+nop2)%1000000007;
            leave=(nop1+op1)%1000000007;
            nop2=nop1,op2=op1,op1=take,nop1=leave;
            dp[i]=(take+leave)%1000000007;
        }
        long long ans=0;
        for(int i=0;i<=n;++i)
        {
            int l=max(0,i-1),r=n-i;
            ans+=(dp[l]*dp[r])%1000000007;
        }
        return ans%1000000007;
    }
};