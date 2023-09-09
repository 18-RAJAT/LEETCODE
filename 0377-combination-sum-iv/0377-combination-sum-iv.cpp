class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        unsigned int dp[target+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1;i<=target;++i)
        {
            for(auto&j:nums)
            {
                if(i>=j)
                {
                    dp[i]+=dp[i-j];
                }
            }
        }
        return dp[target];
    }
};