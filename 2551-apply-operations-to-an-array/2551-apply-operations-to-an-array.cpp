class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n-1;++i)
        {
            if(nums[i]==nums[i+1])nums[i]*=2,nums[i+1]=0;
        }
        vector<int>res;
        for(auto& it:nums)if(it)res.push_back(it);
        while(res.size()<n)res.push_back(0);
        return res;
    }
};