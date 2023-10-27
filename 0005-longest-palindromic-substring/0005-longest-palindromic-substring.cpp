class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int dp[n][n][2];//0 for start and 1 for end
        memset(dp,0,sizeof(dp));
        int ans=1;
        int start=0;
        for(int i=0;i<n;++i)
        {
            dp[i][i][0]=1;
            dp[i][i][1]=1;
        }
        for(int i=0;i<n;++i)
        {
            if(s[i]==s[i+1])//if two consecutive characters are same
            {
                dp[i][i+1][0]=1;//start
                dp[i][i+1][1]=1;//end
                ans=2;//length
                start=i;//start index
            }
        }
        for(int i=2;i<n;++i)
        {
            for(int j=0;j<n-i;++j)
            {
                if(s[j]==s[j+i] && dp[j+1][j+i-1][0])//if start and end of substring is same and the substring between them is also a palindrome
                {
                    dp[j][j+i][0]=1;//start
                    dp[j][j+i][1]=1;//end
                    ans=i+1;//length
                    start=j;//start index
                }
            }
        }
        return s.substr(start,ans);
    }
};