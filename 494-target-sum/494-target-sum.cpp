class Solution {
public:
   int helper(vector<int>&nums,int&target,int idx,int sum)
   {
       if(idx==nums.size())
       {
           if(sum==target){return 1;}return 0;
       }
       int ct=0;
       ct=ct+helper(nums,target,idx+1,sum-nums[idx]);
       ct=ct+helper(nums,target,idx+1,sum+nums[idx]);
       return ct;
   }
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(nums,target,0,0);
    }
};