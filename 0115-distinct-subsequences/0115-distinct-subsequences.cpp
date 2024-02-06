class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;++i)
        {
            dp[i][0]=1;
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                (s[i-1]==t[j-1])?dp[i][j]=(long long)dp[i-1][j-1]+dp[i-1][j]:dp[i][j]=(long long)dp[i-1][j];
            }
        }
        return (long long)dp[n][m];
    }
};