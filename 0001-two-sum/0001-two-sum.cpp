class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>sum;
        for(int i=0;i<nums.size();++i)
        {
            if(sum.find(nums[i])!=sum.end())
            {
                return {sum[nums[i]],i};
            }
            else
            {
                sum[target-nums[i]]=i;
            }
        }
        return {-1,-1};
    }
};