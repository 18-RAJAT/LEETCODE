class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        // function<int(int,int)>LPS=[&](int i,int j)->int
        // {
        //     if(i>j)
        //     {
        //         return 0;
        //     }
        //     if(i==j)
        //     {
        //         return 1;
        //     }
        //     //already compute
        //     if(dp[i][j]!=0)
        //     {
        //         return dp[i][j];
        //     }
        //     if(s[i]==s[j])
        //     {
        //         int dpState=LPS(i+1,j-1);
        //         return 2+dpState;
        //     }
        //     return max(LPS(i+1,j),LPS(i,j-1));
        // };
        // return LPS(0,s.size()-1);
        
        for(int i=0;i<n;++i)
        {
            dp[i][i]=1;
        }
        for(int i=n-1;i>=0;--i)
        {
            for(int j=i+1;j<n;++j)
            {
                if(s[i]==s[j])
                {
                    int dpState=dp[i+1][j-1];
                    dp[i][j]=2+dpState;
                }
                else
                {
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};