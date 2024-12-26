class Solution {
public:
    int recur(vector<int>&nums,int target,int sum,int index)
    {
        if(nums.size()<=index)
        {
            return(sum==target)?1:0;
        }
        return recur(nums,target,sum-nums[index],index+1)+recur(nums,target,sum+nums[index],index+1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return recur(nums,target,0,0);
    }
};