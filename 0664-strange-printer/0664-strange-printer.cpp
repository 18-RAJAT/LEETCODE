class Solution {
public:
    int f(int l,int r,string& s,vector<vector<int>>& dp){
        if(l==r) return 1;
        if(l>r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        int ans=1+f(l+1,r,s,dp);
        for(int i=l+1;i<=r;++i)
        {
            if(s[i]==s[l]) ans=min(ans,f(l+1,i-1,s,dp)+f(i,r,s,dp));
        }
        return dp[l][r]=ans;
    }
    int strangePrinter(string s) {
        vector<vector<int>> dp(s.size()+1,vector<int> (s.size()+1,-1));
        return f(0,s.size()-1,s,dp);
    }
};