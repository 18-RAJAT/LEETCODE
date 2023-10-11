class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int dp[n][n][2];
        memset(dp,0,sizeof(dp));
        int ans=1;
        int start=0;
        for(int i=0;i<n;++i)
        {
            dp[i][i][0]=1;//even length
            dp[i][i][1]=1;//odd length
        }
        for(int i=0;i<n-1;++i)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1][0]=1;
                dp[i][i+1][1]=1;
                ans=2;
                start=i;//starting idx of longest palindrome
            }
        }
        for(int k=3;k<=n;++k)//k is length of substring
        {
            for(int i=0;i<n-k+1;++i)//i is starting idx of substring
            {
                int j=i+k-1;//calculating ending idx of substring
                if(s[i]==s[j] && dp[i+1][j-1][0])//if first and last char are same and substring between them is palindrome
                {
                    dp[i][j][0]=1;
                    dp[i][j][1]=1;
                    if(k>ans)//if current length is greater than previous length
                    {
                        ans=k;//update length
                        start=i;//update starting idx
                    }
                }
            }
        }
        return s.substr(start,ans);  
    }
};