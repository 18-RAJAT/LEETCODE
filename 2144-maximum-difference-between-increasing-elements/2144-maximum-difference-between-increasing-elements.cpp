class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int tmp=nums[0],ans=-1;
        for(int i=1;i<nums.size();++i)
        {
            if(nums[i]>tmp)ans=max({nums[i]-tmp,ans});
            if(nums[i]<tmp)tmp=nums[i];
        }
        return ans;
    }
};