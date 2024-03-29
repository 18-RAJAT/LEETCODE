class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        auto min=[&](int a,int b)->int
        {
            return a<b?a:b;
        };
        int R=grid.size();
        int C=grid[0].size();
        
        for(int i=0;i<R;++i)
        {
            for(int j=0;j<C;++j)
            {
                if(i==0 and j==0)
                {
                    continue;
                }
                else if(i==0)
                {
                    grid[i][j]+=grid[i][j-1];
                }
                else if(j==0)
                {
                    grid[i][j]+=grid[i-1][j];
                }
                else
                {
                    int minimum=min(grid[i][j-1],grid[i-1][j]);
                    grid[i][j]+=minimum;
                }
            }
        }
        return grid[R-1][C-1];
    }
};