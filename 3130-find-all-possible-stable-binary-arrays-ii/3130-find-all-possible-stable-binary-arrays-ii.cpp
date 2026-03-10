#define ll long long
class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        int mod=1e9+7;
        vector<vector<int>>dp(zero+1,vector<int>(one+1,0)),ndp(zero+1,vector<int>(one+1,0));
        for(int i=1; i<=min(zero,limit);++i)dp[i][0]=1;
        for(int j=1;j<=min(one,limit);++j)ndp[0][j]=1;
        for(int i=1;i<=zero;++i)
        {
            for(int j=1;j<=one;++j)
            {
                ll ret=(ll)dp[i-1][j]+ndp[i-1][j];
                if(i-limit-1>=0)ret-=ndp[i-limit-1][j];
                dp[i][j]=(ret%mod+mod)%mod;
                ll val1=(ll)dp[i][j-1] + ndp[i][j-1];
                if(j-limit-1>=0)val1-=dp[i][j-limit-1];
                ndp[i][j]=(val1%mod+mod)%mod;
            }
        }
        return ((ll)dp[zero][one]+ndp[zero][one])%mod;
    }
};