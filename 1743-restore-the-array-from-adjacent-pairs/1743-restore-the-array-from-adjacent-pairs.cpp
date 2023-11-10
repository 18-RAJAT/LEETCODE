class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>>mp;
        for(auto& it:adjacentPairs)
        {
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }
        vector<int>ans;
        for(auto& it:mp)
        {
            if(it.second.size()==1)
            {
                ans.push_back(it.first);
                ans.push_back(it.second[0]);
                break;
            }
        }
        while(ans.size()<adjacentPairs.size()+1)
        {
            int x=ans.back();
            int y=ans[ans.size()-2];
            for(auto& it:mp[x])
            {
                if(it==y)
                {
                    continue;
                }
                else
                {
                    ans.push_back(it);
                    break;
                }
            }
        }
        return ans;
    }
};