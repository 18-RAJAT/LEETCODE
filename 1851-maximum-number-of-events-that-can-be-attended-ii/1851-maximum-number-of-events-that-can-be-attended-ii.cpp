class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n=events.size();
        sort(events.begin(),events.end());
        vector<int>ar(n);
        for(int i=0;i<n;++i)ar[i]=events[i][0];
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        for(int i=n-1;~i;--i)
        {
            int UB=upper_bound(ar.begin(),ar.end(),events[i][1])-ar.begin();
            for(int j=1;j<=k;++j)
            {
                dp[i][j]=max(dp[i+1][j],events[i][2]+dp[UB][j-1]);
            }
        }
        return dp[0][k];
    }
};