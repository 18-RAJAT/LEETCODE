class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        // map<int,int>mp;
        vector<vector<int>>ans(2);
        int winner[1000001];
        int loser[1000001];
        
        memset(winner,0,sizeof(winner));
        memset(loser,0,sizeof(loser));
        
        for(auto it:matches)
        {
            winner[it[0]]++;
            loser[it[1]]++;
        }
        for(int i=1;i<1000001;++i)
        {
            if(winner[i]>0 and loser[i]==0)
            {
                ans[0].push_back(i);
            }
        }
        for(int i=1;i<1000001;++i)
        {
            if(loser[i]==1)
            {
                ans[1].push_back(i);
            }
        }
        return ans;
    }
};