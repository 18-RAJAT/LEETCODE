class Solution {
public:
    int waysToSplitArray(vector<int>&nums){
        long long leftSum=0,rightSum=0;
        for(auto& it:nums)rightSum+=it;
        int count=0;
        for(int i=0;i<nums.size()-1;++i)
        {
            leftSum+=nums[i],rightSum-=nums[i];
            if(leftSum>=rightSum)count++;
        }
        return count;
    }
};