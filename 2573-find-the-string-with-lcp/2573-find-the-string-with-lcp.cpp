class Solution {
public:
    string findTheString(vector<vector<int>>&lcp){
        int n=lcp.size();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        vector<char>v(n,'a');
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                if(lcp[i][j]==0 && v[i]==v[j])
                {
                    v[j]++;
                }
                if(v[j]>'z')return "";
            }
        }
        for(int i=n-1;~i;--i)
        {
            for(int j=n-1;~j;--j)
            {
                if(v[i]==v[j])
                {
                    dp[i][j]=1;
                    if(i+1<n&&j+1<n)dp[i][j]+=dp[i+1][j+1];
                }
            }
        }
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(lcp[i][j]!=dp[i][j])return "";
            }
        }
        string ans="";
        for(auto& it:v)ans+=it;
        return ans;
    }
};