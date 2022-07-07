class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int a=s1.length(),b=s2.length(),c=s3.length();
        if(a+b!=c){return false;}
        
        bool dp[a+1][b+1];
        for(int i=0;i<a+1;++i)
        {
            for(int j=0;j<b+1;++j)
            {
                if(i==0 and j==0){dp[i][j]=true;}
                else if(i==0)
                {dp[i][j]=(dp[i][j-1] and s2[j-1]==s3[i+j-1]);}
                else if(j==0)
                {dp[i][j]=(dp[i-1][j] and s1[i-1]==s3[i+j-1]);}
                else
                {dp[i][j]=dp[i-1][j] and s1[i-1]==s3[i+j-1] or (dp[i][j-1] and s2[j-1]==s3[i+j-1]);}
            }
        }
        return dp[a][b];
    }
};