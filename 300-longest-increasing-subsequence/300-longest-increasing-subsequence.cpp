class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n,0);
        
        dp[0] = 1;
        int answer = 1;
        
        for(int i=1;i<n;++i)
        {
            for(int j=i-1;j>=0;--j)
            {
                if(nums[j] < nums[i] and dp[i] < dp[j])
                {
                    dp[i] = dp[j];
                }
            }
            dp[i]++;
            
            answer = max(answer,dp[i]);
        }
        
        return answer;
    }
};