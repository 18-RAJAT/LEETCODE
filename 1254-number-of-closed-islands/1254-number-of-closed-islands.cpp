class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        
        int closed = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(grid[i][j] == 0 and isClosedIsland(grid,i,j))
                {
                    closed++;
                }
            }
        }
    return closed;
   }
    
    bool isClosedIsland(vector<vector<int>>& grid,int i,int j)
    {
        if(i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size())
        {
            return false;
        }
        
        if(grid[i][j] == 1)
        {
            return true;
        }
        
        grid[i][j] = 1;
        
        bool x1 = isClosedIsland(grid,i-1,j);
        bool x2 = isClosedIsland(grid,i,j-1);
        bool x3 = isClosedIsland(grid,i+1,j);
        bool x4 = isClosedIsland(grid,i,j+1);
        
        return x1 and x2 and x3 and x4;
    }
    
};