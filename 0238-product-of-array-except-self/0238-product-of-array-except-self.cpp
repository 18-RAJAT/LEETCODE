class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);
        dp[0]=1;
        int suffix=1;
        for(int i=1;i<n;++i)
        {
            dp[i]=dp[i-1]*nums[i-1];
        }
        for(int i=n-1;~i;--i)
        {
            dp[i]*=suffix;
            suffix*=nums[i];
        }
        return dp;
    }
};