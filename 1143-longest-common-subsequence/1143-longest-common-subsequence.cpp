// class Solution {
// public:
//     int LCS(string s1,string s2,int n,int m)
// {
//     if(n==0 or m==0){return 0;}
//     if(s1[n-1]==s2[m-1]){return LCS(s1,s2,n-1,m-1)+1;}
//     else{return max(LCS(s1,s2,n-1,m),LCS(s1,s2,n,m-1));}
// }
//     int longestCommonSubsequence(string t1, string t2) {
        // int n=t1.length();
        // int m=t2.length();
        // return LCS(t1,t2,n,m);
//     }
// };

class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        int dp[t1.length()+1][t2.length()+1];
        int n=t1.length();int m=t2.length();
        for(int i=0;i<=n;++i)
        {
            for(int j=0;j<=m;++j)
            {
                if(i==0 or j==0){dp[i][j]=0;}
                else
                {
                    if(t1[i-1]==t2[j-1]){dp[i][j]=dp[i-1][j-1]+1;}
                    else{dp[i][j]=max(dp[i-1][j],dp[i][j-1]);}
                }
            }
        }
        return dp[n][m];
    }
};