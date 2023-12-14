class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int>row(n,0),col(m,0);
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                row[i]+=grid[i][j];
                col[j]+=grid[i][j];
            }
        }
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                grid[i][j]=(row[i]+col[j])-(grid[i].size()-row[i]+grid.size()-col[j]);
            }
        }
        return grid;
    }
};