class Solution {
public:
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
bool dfs(vector<vector<char>>&grid,vector<vector<bool>>&visited,int x,int y,int p1,int p2,char current)
{
    visited[x][y]=true;
    for(int i=0;i<4;++i)
    {
        int x1=x+dx[i];
        int y1=y+dy[i];
        if(x1<0 or x1>=grid.size() or y1<0 or y1>=grid[0].size() or grid[x1][y1]!=current)   {continue;}
        
        if(visited[x1][y1] and (x1!=p1 or y1!=p2)){return true;}
        if(visited[x1][y1]){continue;}
        if(dfs(grid,visited,x1,y1,x,y,current)){return true;}
    }
    return false;
}
    
    bool containsCycle(vector<vector<char>>&grid)
    {
        int r=grid.size();
        int c=grid[0].size();
        
        vector<vector<bool>>vis(r,vector<bool>(c,false));
        
        for(int i=0;i<r;++i)
        {
            for(int j=0;j<c;++j)
            {
                if(!vis[i][j])
                {
                    if(dfs(grid,vis,i,j,1,1,grid[i][j])){return true;}
                }
            }
        }
        return false;
    }
};