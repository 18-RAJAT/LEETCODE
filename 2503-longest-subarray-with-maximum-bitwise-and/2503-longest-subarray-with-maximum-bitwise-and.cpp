class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int mx=*max_element(nums.begin(),nums.end());
        int ans=0,cur=0;
        for(auto& it:nums)
        {
            ((it==mx)?cur++:(ans=max(ans,cur),cur=0));
        }
        ans=max(cur,ans);
        return ans;
    }
};