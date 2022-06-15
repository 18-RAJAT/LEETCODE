class Solution {
public:
      int lcs(string s1,string s2)
      {
        int dp[s1.length()+1][s2.length()+1];
        int n=s1.length();
        int m=s2.length();

        for(int i=0;i<=n;++i)
        {
            for(int j=0;j<=m;++j)
            {
                if(i==0 or j==0){dp[i][j]=0;}
                else
                {
                    if(s1[i-1]==s2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                    else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
}

static bool compare(string &a,string &b)
{
        return a.length()<b.length();
}
        
      int longestStrChain(vector<string>& words)
      {
        int n=words.size();
              vector<int>a(n,1);
              sort(words.begin(),words.end(),compare);
              for(int i=1;i<n;++i)
              {
                      for(int j=0;j<i;++j)
                      {
if(words[i].length()-words[j].length()==1 and 
   lcs(words[i],words[j])==words[j].length() and a[i]<a[j]+1)
                        a[i]=a[j]+1;
                      }
              }
              return *max_element(a.begin(),a.end());
      }
};