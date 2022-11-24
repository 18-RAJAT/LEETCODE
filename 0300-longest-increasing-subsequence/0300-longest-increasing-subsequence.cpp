// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
        
//         //level
//         int dp[n];
//         memset(dp,0,sizeof(dp));
        
//         int ct=0;
//         dp[0]=1;
//         int answer=1;
//         //choice
//         for(int i=1;i<n;++i)
//         {
//             for(int j=n-1;j>=0;--j)
//             {
//                 //check
//                 if(nums[i]>nums[j] and dp[i]<dp[j])
//                 {
//                     //move
//                     dp[i]=dp[j];
//                 }
//             }
//             dp[i]++;
//             answer=max(answer,dp[i]);
//         }
//         // answer=max(answer,dp[i]);
//         //save and return
//         return answer;
//     }
// };




//recursive soln
class Solution {
public:
    int recursive(vector<int>&nums,vector<int>&dp,int idx)
    {
        int n=nums.size();
        // int idx=0;
        if(idx==n)
        {
            return 0;
        }
        
        if(dp[idx]>1)
        {
            return dp[idx];
        }
        
        int ans=0;
        for(int i=idx+1;i<n;++i)
        {
            if(nums[idx]<nums[i])
            {
                //max
                ans=max(1+recursive(nums,dp,i),ans);
            }
        }
        return dp[idx]=ans;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int mx=0;
        int n=nums.size();
        // int dp[n];int mx;
        vector<int>dp(n);
        // dp[n]=1;        
        // int mx=0;
        for(int i=0;i<n;++i)
        {
            dp[i]=1;
        }
        
        for(int i=0;i<n;++i)
        {
            mx=max(1+recursive(nums,dp,i),mx);
            // mx++;
        }
        return mx;
        // cout<<mx<<"\n";
    }
};