class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int left=start,right=start,ans=INT_MAX;
        while(left>=0)
        {
            if(nums[left]==target)ans=min(ans,start-left);
            left--;
        }
        while(right<nums.size())
        {
            if(nums[right]==target)ans=min(ans,right-start);
            right++;
        }
        return ans;
    }
};