class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;
        map<int,vector<int>>store;
        vector<vector<int>>ans;
        for(auto& it:nums)
        {
            mp[it]++;
            store[mp[it]].push_back(it);
        }
        for(auto& it:store)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};