class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(auto& it:nums)
        {
            string s=to_string(it);
            if(~s.size()&1)ans++;
        }
        return ans;
    }
};