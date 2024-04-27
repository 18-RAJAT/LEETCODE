class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n=ring.size(),m=key.size();
        vector<vector<int>>dp(m+1,vector<int>(n,1e9));
        dp[0][0]=0;
        for(int i=1;i<=m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(ring[j]==key[i-1])
                {
                    for(int k=0;k<n;++k)
                    {
                        if(dp[i-1][k]!=1e9)
                        {
                            int diff=abs(j-k);
                            dp[i][j]=min(dp[i][j],dp[i-1][k]+min(diff,n-diff));
                        }
                    }
                }
            }
        }
        return *min_element(dp[m].begin(),dp[m].end())+m;
    }
};