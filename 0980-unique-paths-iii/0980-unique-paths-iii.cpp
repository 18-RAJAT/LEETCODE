class Solution {
public:
    int xLen,yLen,totalZeros=0,res=0,cell,x,y;
    void dfs(vector<vector<int>>& grid,int x,int y) 
    {
        if(x<0 or y<0 or x==xLen or y==yLen)
        {
            return;
        }
        cell = grid[y][x];
        if(cell) 
        {
            // increasing res if we reached the point and touched all available cell
            res+=cell==2 and !totalZeros;
            // res+=!totalZeros;
            return;
        }
        //visited marked
        grid[y][x]=-1;
        totalZeros--;
        dfs(grid,x,y-1);
        dfs(grid,x+1,y);
        dfs(grid,x,y+1);
        dfs(grid,x-1,y);
        // backtracking cell as if visited
        grid[y][x]=0;
        totalZeros++;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        yLen=grid.size();
        xLen=grid[0].size();
        for(int p=0;p<yLen;++p) 
        {
            for(int q=0;q<xLen;++q) 
            {
                cell=grid[p][q];
                // finding the starting point
                if(cell==1) 
                {
                    x=q;
                    y=p;
                }
                totalZeros+=!cell;
            }
        }
        dfs(grid,x,y-1);
        dfs(grid,x+1,y);
        dfs(grid,x,y+1);
        dfs(grid,x-1,y);
        return res;
    }
};