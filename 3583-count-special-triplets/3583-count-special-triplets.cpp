class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,int>suf,pref;
        for(auto& it:nums)suf[it]++;
        long long ans=0;
        for(auto& it:nums)
        {
            suf[it]--;
            ans+=(long long)pref[2*it]*suf[2*it];
            pref[it]++;
        }
        return ans%1000000007;
    }
};