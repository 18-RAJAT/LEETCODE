class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) 
    {
        int count=0;
        int szx=grid.size();
        int szy=grid[0].size();
        for(int i=0;i<szx-2;++i)
        {
            for(int j=0;j<szy-2;++j)
            {
                if(grid[i+1][j+1]==5 && judge(grid,i,j))
                    count++;
            }
        }
        return count;
    }
    
    bool judge(vector<vector<int>> &grid,int i,int j)
    { 
        if(grid[i][j]==5)return false;
        for(int x=i;x<i+3;++x)
        {                                      
            for(int y=j;y<j+3;++y)
            {
                int curele=grid[x][y];
                if(curele>9)return false;
            }
        }
        for(int x=i;x<i+3;++x)
        {
            if(grid[x][j]+grid[x][j+1]+grid[x][j+2]!=15)return false;
        }
        for(int y=j;y<j+3;++y)
        {
            if(grid[i][y]+grid[i+1][y]+grid[i+2][y]!=15)return false;
        }
        if(grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2]!=15)return false;
        if(grid[i+2][j]+grid[i+1][j+1]+grid[i][j+2]!=15)return false;
        return true;
    }
};