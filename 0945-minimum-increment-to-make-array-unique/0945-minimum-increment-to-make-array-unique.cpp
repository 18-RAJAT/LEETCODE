class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int maxi=nums[0],operation=0;
        for(int i=0;i<n;++i)
        {
            if(maxi<nums[i])maxi=nums[i];
            operation+=maxi-nums[i];
            maxi++;
        }
        return operation;
    }
};