class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maximumSubArray=INT_MIN;
        
        int dp[n];
        memset(dp,0,sizeof(dp));
        
        dp[0]=nums[0];
        maximumSubArray=dp[0];
        
        for(int i=1;i<n;++i)
        {
            dp[i]=max(nums[i],dp[i-1]+nums[i]);//if the sum till (i-1)th index is (-)ve then we will not add it to the current element and start a new subarray from the current element itself.
            maximumSubArray=max(maximumSubArray,dp[i]);
        }
        return maximumSubArray;
    }
};