class Solution {
public:
    int ans,n,dp[1001];
    int solve(string s,int p)
    {
        if(p==n)return 1;
        if(s[p]=='0')return 0;
        if(dp[p]!=-1)return dp[p];
        
        int ans=solve(s,p+1);
        if(s[p]=='1' and p+1<n)ans+=solve(s,p+2);
        
        if(s[p]=='2' and p+1<n and s[p+1]<='6')ans+=solve(s,p+2);
        
        return dp[p]=ans;
    }
    int numDecodings(string s) {
        ans=0;
        n=s.length();
        memset(dp,-1,sizeof(dp));
        return solve(s,0);
    }
};