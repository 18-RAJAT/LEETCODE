class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n=points.size(),m=points[0].size();
        vector<long long>dp(m);
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)dp[j]+=points[i][j];
            for(int j=1;j<m;++j)dp[j]=max(dp[j],dp[j-1]-1);
            for(int j=m-2;j>=0;--j)dp[j]=max(dp[j],dp[j+1]-1);
        }
        return *max_element(dp.begin(),dp.end());
    }
};