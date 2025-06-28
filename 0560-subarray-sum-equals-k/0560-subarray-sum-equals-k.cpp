class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>pref;
        pref[0]=1;
        int ans=0,sum=0;
        for(auto& it:nums)
        {
            sum+=it;
            if(pref.count(sum-k))ans+=pref[sum-k];
            pref[sum]++;
        }
        return ans;
    }
};