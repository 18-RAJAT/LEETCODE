class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        set<int>s;
        int n=grid.size();
        int miss=0,rep=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(s.find(grid[i][j])!=s.end())
                {
                    rep=grid[i][j];
                }
                s.insert(grid[i][j]);
            }
        }
        for(int i=1;i<=n*n;++i)
        {
            if(s.find(i)==s.end())
            {
                miss=i;
                break;
            }
        }
        vector<int>ans;
        ans.push_back(rep);
        ans.push_back(miss);
        return ans;
    }
};