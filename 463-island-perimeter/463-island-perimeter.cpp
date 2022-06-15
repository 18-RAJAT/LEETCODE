class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int result=0;
            int row=grid.size();
            int column=grid[0].size();
            
            for(int i=0;i<row;++i)
            {
                    for(int j=0;j<column;++j)
                    {
                            if(grid[i][j]==1)
                            {
                            result=result+(i==0 or grid[i-1][j]==0?1:0);
                            result=result+(i==row-1 or grid[i+1][j]==0?1:0);
                            result=result+(j==0 or grid[i][j-1]==0?1:0);
                            result=result+(j==column-1 or grid[i][j+1]==0?1:0);
                            }
                    }
            }
            return result;
    }
};