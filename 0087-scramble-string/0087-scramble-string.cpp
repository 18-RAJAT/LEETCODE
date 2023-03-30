class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size()!=s2.size())return false;
        if(s1==s2)return true;
        int n=s1.size();
        vector<vector<vector<bool>>>dp(n,vector<vector<bool>>(n,vector<bool>(n+1,false)));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i][j][1]=(s1[i]==s2[j]);
            }
        }
        for(int len=2;len<=n;len++)
        {
            for(int i=0;i<=n-len;i++)
            {
                for(int j=0;j<=n-len;j++)
                {
                    for(int k=1;k<len;k++)
                    {
                        if((dp[i][j][k] and dp[i+k][j+k][len-k]) or (dp[i][j+len-k][k] and dp[i+k][j][len-k]))
                        {
                            dp[i][j][len]=true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][0][n];
    }
};
