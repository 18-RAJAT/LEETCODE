class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int dp[n][n];
        int count=0;
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
            count++;
        }
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=1;
                count++;
            }
            else
            {
                dp[i][i+1]=0;
            }
        }
        for(int k=3;k<=n;k++)
        {
            for(int i=0;i<n-k+1;i++)
            {
                int j=i+k-1;
                if(s[i]==s[j] && dp[i+1][j-1]==1)
                {
                    dp[i][j]=1;
                    count++;
                }
                else
                {
                    dp[i][j]=0;
                }
            }
        }
        return count;
    }
};