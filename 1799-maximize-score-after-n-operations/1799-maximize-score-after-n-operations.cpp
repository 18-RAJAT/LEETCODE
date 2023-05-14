class Solution {
public:
    
    int get(int optNo,int mask,vector<int> &nums, vector<vector<int>> &dp){
        if(optNo>nums.size()) return 0;
                
        if(dp[optNo][mask]!=-1) return dp[optNo][mask];
        
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(mask&(1<<i))
            {
                for(int j=0;j<nums.size();j++)
                {
                    if(j!=i and mask&(1<<j))
                    {
                        ans=max(ans,optNo*__gcd(nums[i],nums[j])+get(optNo+1,(mask^(1<<i)^(1<<j)),nums,dp));
                    }
                }
            }
        }
        
        dp[optNo][mask]=ans;
        return ans;
    }
    
    int maxScore(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>((1<<14),-1));
        
        return get(1,(1<<n)-1,nums,dp);
    }
};