class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int,vector<int>>mp;
        int n=nums.size();
        int mx=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<nums[i].size();++j)
            {
                mp[i+j].push_back(nums[i][j]);
                mx=max(mx,i+j);
            }
        }
        vector<int>ans;
        for(int i=0;i<=mx;++i)
        {
            for(int j=mp[i].size()-1;j>=0;--j)
            {
                ans.push_back(mp[i][j]);
            }
        }
        return ans;
    }
};