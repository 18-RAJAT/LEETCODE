class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        
        //level
        int dp[n];
        memset(dp,0,sizeof(dp));
        
        int ct=0;
        dp[0]=1;
        int answer=1;
        //choice
        for(int i=1;i<n;++i)
        {
            for(int j=n-1;j>=0;--j)
            {
                //check
                if(nums[i]>nums[j] and dp[i]<dp[j])
                {
                    //move
                    dp[i]=dp[j];
                }
            }
            dp[i]++;
            answer=max(answer,dp[i]);
        }
        // answer=max(answer,dp[i]);
        //save and return
        return answer;
    }
};