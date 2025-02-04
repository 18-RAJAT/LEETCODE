class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size();
        int ans=nums[0],curr=nums[0];
        for(int i=1;i<n;++i)
        {
            if(nums[i]>nums[i-1])curr+=nums[i];
            else curr=nums[i];
            ans=max(ans,curr);
        }
        return ans;
    }
};