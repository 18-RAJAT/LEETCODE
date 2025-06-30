class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto& it:nums)mp[it]++;
        int ans=0;
        for(auto& [f,s]:mp)
        {
            if(mp.count(f+1))
            {
                int cur=s+mp[f+1];
                ans=max(ans,cur);
            }
        }
        return ans;
    }
};