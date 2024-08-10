class Solution {
public:
    int vis[35][35][4];
    void fun(vector<string>& grid,int n,int x,int y,int ch)
    {
        if(x>=n||y>=n||x<0||y<0||vis[x][y][ch])return;
        vis[x][y][ch]=1;
        
        if(ch==0)
        {
            fun(grid,n,x-1,y,2);
        }
        if(ch==1)
        {
            fun(grid,n,x,y+1,3);
        }
        if(ch==2)
        {
            fun(grid,n,x+1,y,0);
        }
        if(ch==3)
        {
            fun(grid,n,x,y-1,1);
        }
        if(grid[x][y]=='/')
        {
            fun(grid,n,x,y,ch^3);
        }
        else if(grid[x][y]=='\\')
        {
            fun(grid,n,x,y,ch^1);
        }
        else
        {
            fun(grid,n,x,y,0);
            fun(grid,n,x,y,1);
            fun(grid,n,x,y,2);
            fun(grid,n,x,y,3);
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size(),i,j,ans=0;
        memset(vis,0,sizeof(vis));
        
        for(i=0;i<n;++i)
        {
            for(j=0;j<n;++j)
            {
                for(int k=0;k<4;++k)
                {
                    if(!vis[i][j][k])
                    {
                        ans++;
                        fun(grid,n,i,j,k);
                    }
                }
            }
        }
        
        return ans;
    }
};