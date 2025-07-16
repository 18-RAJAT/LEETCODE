class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int e=0,o=0;
        for(auto& it:nums)
        {
            (it&1)?o++:e++;
        }
        int dp=0,ndp=0;
        for(auto& it:nums)
        {
            (it&1)?ndp=max(ndp,dp+1):dp=max(dp,ndp+1);
        }
        return max({e,o,dp,ndp});
    }
};