class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n=nums.size(),i=0,ans=0;
        for(int j=1;j<n-1;++j)
        {
            if((nums[i]<nums[j] && nums[j+1]<nums[j]) || (nums[j]<nums[i] && nums[j]<nums[j+1]))ans++,i=j;
        }
        return ans;
    }
};