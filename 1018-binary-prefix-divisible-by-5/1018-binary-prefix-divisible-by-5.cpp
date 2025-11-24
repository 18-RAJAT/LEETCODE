class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool>ans;
        int res=0;
        for(auto& it:nums)
        {
            res=(res*2+it)%5;
            ans.push_back(res==0);
        }
        return ans;
    }
};