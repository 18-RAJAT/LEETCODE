class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size(),ans=INT_MAX;
        unordered_map<int,vector<int>>m;
        for(int i=0;i<n;++i)
        {
            m[nums[i]].push_back(i);
            if(m[nums[i]].size()==3)
            {
                ans=min(ans,2*(m[nums[i]][2]-m[nums[i]][0]));
                m[nums[i]].erase(m[nums[i]].begin());
            }
        }
        return (ans==INT_MAX?-1:ans);
    }
};