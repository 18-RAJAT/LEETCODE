class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& grid,int m,int n,queue<pair<int,int>>& q)
    {
        if(i<0 or j<0 or i>m-1 or j>n-1 or grid[i][j]==0 or grid[i][j]==2)
        {
            return;
        }
        
        grid[i][j]=2;
        q.push(make_pair(i,j));
        
        dfs(i-1,j,grid,m,n,q);
        dfs(i+1,j,grid,m,n,q);
        dfs(i,j-1,grid,m,n,q);
        dfs(i,j+1,grid,m,n,q);
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        queue<pair<int,int>>q;
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(grid[i][j]==1)
                {
                    dfs(i,j,grid,m,n,q);
                    break;
                }
            }
            if(not q.empty())
                break;
        }
        int Bridge=0;
        while(not q.empty())
        {
            Bridge++;
            int temp=q.size();
            for(int i=0;i<temp;++i)
            {
                auto frontVal=q.front();q.pop();
                vector<int> dx={-1,0,0,1};
                vector<int> dy={0,-1,1,0};
                    
                for(int j=0;j<4;++j)
                {
                    int x=frontVal.first+dx[j];
                    int y=frontVal.second+dy[j];
                        
                    if(x>=0 and x<m and y>=0 and y<n and (grid[x][y]==0 or grid[x][y]==1))
                    {
                        if(grid[x][y]==0)
                        {
                            q.push(make_pair(x,y));
                            grid[x][y]=2;
                        }
                        else
                        {
                            return Bridge-1;
                        }
                    }
                }
            }
        }
        return 0;
    }
};