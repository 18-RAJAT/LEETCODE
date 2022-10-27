class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        // sort(nums.begin(),nums.end());
        int matches=0;
        int prefixSum=0;
        map<int,int>idx;
        // for(auto &it:nums)
        for(int i=0;i<n;++i)
        {
            idx[prefixSum]++;
            prefixSum+=nums[i];
            matches+=idx[prefixSum-k];
        }
        return matches;
    }
};