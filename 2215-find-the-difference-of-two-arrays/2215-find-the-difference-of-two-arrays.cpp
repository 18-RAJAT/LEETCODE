class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>ans(2);
        set<int>first,second;
        for(auto &n1:nums1)
        {
            first.insert(n1);
        }
        for(auto &n2:nums2)
        {
            second.insert(n2);
        }
        
        for(auto &f:first)
        {
            if(second.find(f)==second.end())
            {
                ans[0].push_back(f);
            }
        }
        for(auto &s:second)
        {
            if(first.find(s)==first.end())
            {
                ans[1].push_back(s);
            }
        }
        return ans;
    }
};