class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        if(n==2)
        {
            return 2;
        }
        vector<unordered_map<int,int>>dp(n);
        int maxLength=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<i;++j)
            {
                int diff=nums[i]-nums[j];
                dp[i][diff]=dp[j][diff]+1;
                maxLength=max<int>(maxLength,dp[i][diff]);
            }
        }
        return maxLength+1;
    }
};