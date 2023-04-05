class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>cnt;
        int n=nums.size();
        int possible=0;
        int sum=0;
        
        
        cnt[0]=1;
        for(auto& it:nums)
        {
            sum+=it;
            possible+=cnt[sum-k];
            cnt[sum]++;
        }
        return possible;
    }
};