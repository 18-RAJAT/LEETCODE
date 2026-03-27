class Solution {
public:
    bool areSimilar(vector<vector<int>>& grid,int k) {
        int n=grid.size(),m=grid[0].size();
        k=k%m;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(i%2==0)
                {
                    if(grid[i][j]!=grid[i][(j+k)%m])return false;
                }
                else
                {
                    if(grid[i][j]!=grid[i][(j-k+m)%m])return false;
                }
            }
        }
        return true;
    }
};