class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int m=grid[0].size();
        vector<long long>pref(m,grid[0][0]),suf(m,grid[1][m-1]);
        for(int i=1;i<m;++i)pref[i]=pref[i-1]+grid[0][i];
        for(int i=m-2;~i;--i)suf[i]=suf[i+1]+grid[1][i];
        long long ans=LONG_MAX;
        for(int i=0;i<m;++i)
        {
            ans=min(ans,max(suf[0]-suf[i],pref[m-1]-pref[i]));
        }
        return ans;
    }
};