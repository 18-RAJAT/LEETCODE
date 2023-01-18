class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int maxsum=INT_MIN;
        int minsum=INT_MAX;
        int currmax=0;
        int currmin=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            currmax=max(currmax+nums[i],nums[i]);
            maxsum=max(maxsum,currmax);
            currmin=min(currmin+nums[i],nums[i]);
            minsum=min(minsum,currmin);
        }
        if(sum==minsum)
        {
            return maxsum;
        }
        return max(maxsum,sum-minsum);   
    }
};