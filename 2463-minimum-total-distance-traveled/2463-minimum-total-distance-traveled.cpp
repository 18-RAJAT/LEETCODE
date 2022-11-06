#define ll long long
class Solution {
public:
    ll dp[101][101][101],pos[101][101],n,m;
    ll func(int i,int j,int x,vector<int>& r, vector<vector<int>>& f)
    {
        if(i==n)
            return (j==m) ? 1e15 : 1 ;
        if(j==m)
            return 0;
        if(dp[i][j][x]!=-1)
            return dp[i][j][x];
        ll ans = 1e18;
        if(i+1<n)
            ans=func(i+1,j,f[i+1][1],r,f);
        if(x)
            ans=min(ans,pos[i][j] + func(i,j+1,x-1,r,f));
        return dp[i][j][x]=ans;
    }
    
    long long minimumTotalDistance(vector<int>& r, vector<vector<int>>& f) {
        n=f.size(),m=r.size(),sort(begin(r),end(r)),sort(begin(f),end(f)),memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                pos[i][j] = max(f[i][0],r[j]) - min(f[i][0],r[j]);
        return func(0,0,f[0][1],r,f);
    }
};