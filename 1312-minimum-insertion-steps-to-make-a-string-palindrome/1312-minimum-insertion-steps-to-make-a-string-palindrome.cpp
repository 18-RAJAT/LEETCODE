class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;++i)
        {
            dp[i][i]=1;
        }
        for(int i=0;i<n-1;++i)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=2;
            }
            else
            {
                dp[i][i+1]=1;
            }
        }
        for(int i=2;i<n;++i)
        {
            for(int j=0;j<n-i;++j)
            {
                if(s[j]==s[j+i])
                {
                    dp[j][j+i]=2+dp[j+1][j+i-1];
                }
                else
                {
                    dp[j][j+i]=max(dp[j+1][j+i],dp[j][j+i-1]);
                }
            }
        }
        return abs(dp[0][n-1]-n);
    }
};