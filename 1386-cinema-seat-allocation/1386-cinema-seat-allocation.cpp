class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,vector<int>>mp;
        for(auto& it:reservedSeats)
        {
            if(it[1]==1||it[1]==10)continue;
            if(mp.find(it[0])==mp.end())mp[it[0]]={0,0,0,0};
            int j=it[1]/2-1;
            mp[it[0]][j]=1;
        }
        int ans=2*(n-mp.size());
        for(auto& it:mp)
        {
            for(int j=1;j<4;++j)
            {
                if(it.second[j-1]==0 && it.second[j]==0)
                {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};