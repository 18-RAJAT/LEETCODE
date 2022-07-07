// class Solution {
// public:
//     bool helper(string &s1,string &s2,string &s3,int i,int j,int k)
//     {
//         if(s1[i]!=s3[k] and s2[j]!=s3[k]){return false;}
//         if(i>=s1.length() and j>=s2.length()){return true;}
//         if(k==s3.length()){return true;}
        
//          int x=0,y=0,z=0;
//         if(s1[i]==s3[k] and s2[k]!=s3[k])
//         {x=helper(s1,s2,s3,i+1,j,k+1);}
        
//         if(s2[j]==s3[k] and s1[k]!=s3[k])
//         {y=helper(s1,s2,s3,i,j+1,k+1);}
        
//         if(s1[i]==s3[k] and s2[k]==s3[k])
//         {z=helper(s1,s2,s3,i+1,j,k+1) or helper(s1,s2,s3,i,j+1,k+1);}
//         return x or y or z;
//     }
//     bool isInterleave(string s1, string s2, string s3) {
//         int p=s1.length(),q=s2.length(),r=s3.length();
//         if(p+q!=r){return false;}
//         return helper(s1,s2,s3,0,0,0);
//     }
// };




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