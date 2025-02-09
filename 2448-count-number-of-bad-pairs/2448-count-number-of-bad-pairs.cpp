class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;++i)
        {
            mp[i-nums[i]]++;
        }
        long long pairs=0;
        for(int i=0;i<n;++i)
        {
            long long diff=i-nums[i];
            mp[diff]--;
            pairs+=n-i-1-mp[diff];
        }
        return pairs;
    }
};