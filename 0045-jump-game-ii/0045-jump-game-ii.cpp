class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int dp[n];
        memset(dp,0,sizeof(dp));
        dp[0]=0;
        for(int i=1;i<n;i++)
        {
            dp[i]=INT_MAX;
            for(int j=0;j<i;j++)
            {
                if(i<=j+nums[j])
                {
                    dp[i]=min(dp[i],dp[j]+1);
                }
            }
        }
        return dp[n-1];
    }
};