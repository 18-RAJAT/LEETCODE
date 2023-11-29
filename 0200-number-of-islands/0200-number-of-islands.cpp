class Solution {
public:
    void dfs(vector<vector<char>>& grid,int x,int y,int row,int col)
    {
        if(x<0 || x>=row || y<0 || y>=col || grid[x][y]!='1')
        {
            return;
        }
        //marked as VISITED
        grid[x][y]='2';
        
        //TOP
        dfs(grid,x-1,y,row,col);
        //DOWN
        dfs(grid,x+1,y,row,col);
        //LEFT
        dfs(grid,x,y-1,row,col);
        //RIGHT
        dfs(grid,x,y+1,row,col);
    }
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        if(row==0)
        {
            return 0;
        }
        int total_island=0;
        for(int i=0;i<row;++i)
        {
            for(int j=0;j<col;++j)
            {
                //CHECK
                if(grid[i][j]=='1')
                {
                    //CALL
                    dfs(grid,i,j,row,col);
                    total_island++;
                }
            }
        }
        return total_island;
    }
};