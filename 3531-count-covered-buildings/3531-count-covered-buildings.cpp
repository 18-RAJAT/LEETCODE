class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int,set<int>>s1,s2;
        for(auto& it:buildings)
        {
            s1[it[0]].insert(it[1]);
            s2[it[1]].insert(it[0]);
        }
        int ans=0;
        for(auto& it:buildings)
        {
            auto& i=s1[it[0]];
            auto& j=s2[it[1]];
            auto dx=j.lower_bound(it[0]),ux=j.upper_bound(it[0]);
            auto dy=i.lower_bound(it[1]),uy=i.upper_bound(it[1]);
            int l=dx!=j.begin(),r=ux!=j.end();
            int u=dy!=i.begin(),d=uy!=i.end();
            if(u && d && l && r)ans++;
        }
        return ans;
    }
};