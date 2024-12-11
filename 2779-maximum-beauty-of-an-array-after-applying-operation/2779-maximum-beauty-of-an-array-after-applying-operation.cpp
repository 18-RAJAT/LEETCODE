class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i+=1)
        {
            mp[nums[i]-k]++;
            mp[nums[i]+k+1]--;
        }
        int ans(0),ert(0);
        for(auto&it:mp)
        {
            ert+=it.second;
            ans=max<int>(ans,ert);
        }
        return ans;
    }
};