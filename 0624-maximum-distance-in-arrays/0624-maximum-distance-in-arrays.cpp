class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int ans=0,l=10005,h=-10005;
        for (auto& v:arrays)
        {
            int l1=v.front(),h1=v.back();
            ans=max({ans,h-l1,h1-l});
            h=max(h,h1),l=min(l,l1);
        }
        return ans;
    }
};