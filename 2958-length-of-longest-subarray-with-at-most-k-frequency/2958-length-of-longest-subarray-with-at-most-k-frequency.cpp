class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mp;
        int l=0,r=0;
        int ans=1;
        while(r<n)
        {
            mp[nums[r]]++;
            while(mp[nums[r]]>k)
            {
                mp[nums[l++]]--;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};