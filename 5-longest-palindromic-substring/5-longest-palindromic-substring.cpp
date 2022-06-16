class Solution {
public:
  string longestPalindrome(string s)
  {
      int n=s.size();
          if(n==0){return " ";}
          bool dp[n][n];
          memset(dp,0,sizeof(dp));
                  for(int i=0;i<n;++i)dp[i][i]=true;
          string answer="";
          answer=answer+s[0];
          
          for(int i=n-1;i>=0;--i)
          {
                  for(int j=i+1;j<n;++j)
                  {
                          if(s[i]==s[j])
                          {
                                  if(j-i==1 or dp[i+1][j-1])
                                  {
                                          dp[i][j]=true;
                                          if(answer.size()<j-i+1)
                                          {answer=s.substr(i,j-i+1);}
                                  }
                          }
                  }
          }
          return answer;
  }
};