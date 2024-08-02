class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ones=0;
        for(auto& it:nums)
        {
            if(it)ones++;
        }
        int m=0;
        for(int i=0;i<ones;++i)
        {
            if(nums[i])m++;
        }
        int ans=m;
        for(int i=1;i<nums.size();++i)
        {
            if(nums[i-1])m--;
            if(nums[(i-1+ones)%nums.size()])m++;
            ans=max(ans,m);
        }
        return ones-ans;
    }
};