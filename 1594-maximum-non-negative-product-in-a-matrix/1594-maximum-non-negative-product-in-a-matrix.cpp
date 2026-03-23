#define ll long long int
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int mod=1000000007;
        int n=grid.size(),m=grid[0].size();
        vector<vector<ll>>dp(n,vector<ll>(m));
        vector<vector<ll>>ndp(n,vector<ll>(m));
        dp[0][0]=grid[0][0];
        for(int i=1;i<n;++i)dp[i][0]=ndp[i][0]=grid[i][0]*dp[i-1][0];
        for(int i=1;i<m;++i)dp[0][i]=ndp[0][i]=grid[0][i]*dp[0][i-1];
        for(int i=1;i<n;++i)
        {
            for(int j=1;j<m;++j)
            {
                ll tmp=grid[i][j];
                ll mx=dp[i][j-1]*tmp,mn=ndp[i][j-1]*tmp;
                ll mx1=dp[i-1][j]*tmp,mn1=ndp[i-1][j]*tmp;
                dp[i][j]=max({mx,mn,mx1,mn1});
                ndp[i][j]=min({mx,mn,mx1,mn1});
            }
        }
        ll ans=dp.back().back();
        if(ans<0)return -1;
        return ans%mod;
    }
};