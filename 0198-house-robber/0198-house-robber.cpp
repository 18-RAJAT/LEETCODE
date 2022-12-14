class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[n]=0;
        dp[n-1]=nums[n-1];
        for(int i=n-2;i>=0;--i)
        {
            int p=nums[i]+dp[i+2];
            int np=dp[i+1];
            dp[i]=max(p,np);
        }
        return dp[0];
    }
};