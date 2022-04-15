class Solution {
    
    int dfs(vector<vector<int>>& grid,int i,int j)
    {
        int row = grid.size();
        int column = grid[0].size();
        
        if(i < 0 or j < 0 or i >= row or j >= column or grid[i][j] != 1)
        {
            return 0;
        }
        
        grid[i][j] = 2;
        
        return(1 + dfs(grid,i+1,j) + dfs(grid,i-1,j) + dfs(grid,i,j+1) + dfs(grid,i,j-1));
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int column = grid[0].size();
        
        int result = 0;
        for(int i=0;i<row;++i)
        {
            for(int j=0;j<column;++j)
            {
                if(grid[i][j] == 1)
                {
                    result = max(result,dfs(grid,i,j));
                }
            }
        }
        return result;
    }
};