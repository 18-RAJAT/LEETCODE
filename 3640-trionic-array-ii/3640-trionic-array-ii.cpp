class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n=nums.size();
        long long ans=LLONG_MIN,mx=LLONG_MIN;
        vector<long long>dp1(n,0),dp2(n,mx),dp3(n,mx),dp4(n,mx);
        for(int i=0;i<n;++i)dp1[i]=nums[i];
        for(int i=1;i<n;++i)
        {
            if(nums[i]>nums[i-1])
            {
                if(dp2[i-1]!=mx)dp2[i]=max(dp2[i],dp2[i-1]+nums[i]);
                dp2[i]=max(dp2[i],dp1[i-1]+nums[i]);
            }
        }
        for(int i=1;i<n;++i)
        {
            if(nums[i]<nums[i-1])
            {
                if(dp3[i-1]!=mx)dp3[i]=max(dp3[i],dp3[i-1]+nums[i]);
                if(dp2[i-1]!=mx)dp3[i]=max(dp3[i],dp2[i-1]+nums[i]);
            }
        }
        for(int i=1;i<n;++i)
        {
            if(nums[i]>nums[i-1])
            {
                if(dp4[i-1]!=mx)dp4[i]=max(dp4[i],dp4[i-1]+nums[i]);
                if(dp3[i-1]!=mx)dp4[i]=max(dp4[i],dp3[i-1]+nums[i]);
            }
            ans=max(ans,dp4[i]);
        }
        return ans;
    }
};