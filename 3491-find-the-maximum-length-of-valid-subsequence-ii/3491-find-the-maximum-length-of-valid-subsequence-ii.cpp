class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size(),ans=0;        
        vector<vector<int>>dp(k,vector<int>(k,0));
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<k;++j)
            {
                ans=max(ans,dp[nums[i]%k][j]=dp[j][nums[i]%k]+1);
            }
        }
        return ans;
    }
};