class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int>dp(3,INT_MIN);
        dp[0]=0;
        for(auto& it:nums)
        {
            vector<int>ndp=dp;
            for(int i=0;i<3;++i)
            {
                int tmp=(i+it%3)%3;
                ndp[tmp]=max(ndp[tmp],dp[i]+it);
            }
            dp=ndp;
        }
        return dp[0];
    }
};