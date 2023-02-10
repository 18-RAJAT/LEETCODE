class Solution {
public:
    struct node{
        int x,y;
        int dist;
    };
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<node>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j,0});
                }
            }
        }
        int ans=0;
        while(!q.empty())
        {
            node temp=q.front();
            q.pop();
            ans=max(ans,temp.dist);
            int x=temp.x;
            int y=temp.y;
            if(x+1<n and grid[x+1][y]==0)
            {
                grid[x+1][y]=1;
                q.push({x+1,y,temp.dist+1});
            }
            if(x-1>=0 and grid[x-1][y]==0)
            {
                grid[x-1][y]=1;
                q.push({x-1,y,temp.dist+1});
            }
            if(y+1<m and grid[x][y+1]==0)
            {
                grid[x][y+1]=1;
                q.push({x,y+1,temp.dist+1});
            }
            if(y-1>=0 and grid[x][y-1]==0)
            {
                grid[x][y-1]=1;
                q.push({x,y-1,temp.dist+1});
            }
        }
        if(ans==0)return -1;
        return ans;  
    }
};