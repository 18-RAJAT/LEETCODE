class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        long long mod=1e9+7,res=0;
        vector<vector<long long>>dp(2,vector<long long>(r+5));
        vector<vector<long long>>ndp(2,vector<long long>(r+5));
        for(int j=l;j<=r;++j)dp[0][j]=dp[1][j]=1;
        for(int i=n-2;~i;--i)
        {
            vector<long long>pref(r+5),suff(r+5);
            for(int j=l;j<=r;++j)pref[j]=(pref[j-1]+dp[1][j])%mod;
            for(int j=r;j>=l;--j)suff[j]=(suff[j+1]+dp[0][j])%mod;
            for(int j=l;j<=r;++j)
            {
                ndp[0][j]=pref[j-1]%mod;
                ndp[1][j]=suff[j+1]%mod;
            }
            swap(dp,ndp);
        }
        for(int j=l;j<=r;++j)res=(res+dp[0][j]+dp[1][j])%mod;
        return res;
    }
};