class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        vector<vector<bool>>dp(n,vector<bool>(n+1,false));
        dp[0][0]=true;
        for(int i=1;i<n;++i)
        {
            for(int j=0;j<i;++j)
            {
                int k=stones[i]-stones[j];
                if(k<=i)
                {
                    dp[i][k]=dp[j][k-1]||dp[j][k]||dp[j][k+1];
                }
            }
        }
        for(int i=0;i<n;++i)
        {
            if(dp[n-1][i])
            {
                return true;
            }
        }
        return false;
    }
};