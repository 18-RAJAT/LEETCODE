class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans;
        for(auto& it:nums)
        {
            bool ok=false;
            for(int i=0;i<=it;++i)
            {
                if((i|(i+1))==it)
                {
                    ans.push_back(i);
                    ok=true;
                    break;
                }
            }
            if(!ok)ans.push_back(-1);
        }
        return ans;
    }
};