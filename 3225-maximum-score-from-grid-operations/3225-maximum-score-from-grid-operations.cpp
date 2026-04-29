class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<long long>>dp(n,vector<long long>(n+1,0));
        for(int j=0;j<n;++j)
        {
            for(int i=0;i<n;++i)dp[j][i+1]=dp[j][i]+grid[i][j];
        }
        vector<long long>ar(n+1,0),br(n+1,0);
        for(int j=1;j<n;++j)
        {
            vector<long long>take(n+1,0),leave(n+1,0);
            for(int i=0;i<=n;++i)
            {
                for(int k=0;k<=n;++k)
                {
                    if(k<i)
                    {
                        long long res=dp[j-1][i]-dp[j-1][k];
                        take[i]=max(take[i],br[k]+res),leave[i]=max(leave[i],br[k]+res);

                    }
                    else
                    {
                        long long res=dp[j][k]-dp[j][i];
                        take[i]=max(take[i],ar[k]+res),leave[i]=max(leave[i],ar[k]);
                    }
                }
            }
            ar=take,br=leave;
        }
        return *max_element(ar.begin(),ar.end());
    }
};