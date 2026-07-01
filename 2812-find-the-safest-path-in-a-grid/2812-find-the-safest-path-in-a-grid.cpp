class Solution {
public:
    array<int,4>dx={-1,0,1,0},dy={0,-1,0,1};
    int n,m;
    vector<pair<int,int>>path;
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        if(grid[0][0]==1||grid[n-1][m-1]==1)return 0;
        vector<vector<int>>dis(n,vector<int>(m,-1e5));
        priority_queue<pair<int,pair<int,int>>>pq;
        dis[0][0]=1e9;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(grid[i][j]==1)
                {
                    path.push_back({i,j});
                    dis[0][0]=min(dis[0][0],i+j);
                }
            }
        }
        pq.push({dis[0][0],{0,0}});
        while(!pq.empty())
        {
            int dist=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            if(x==n-1&&y==m-1)return dist;
            pq.pop();
            if(dist<dis[x][y])continue;
            for(int i=0;i<4;++i)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx==n||nx<0||ny==m||ny<0)continue;
                int temp=dist;
                for(auto it:path)
                {
                    temp=min(temp,abs(nx-it.first)+abs(ny-it.second));
                }
                if(temp>dis[nx][ny])
                {
                    dis[nx][ny]=temp;
                    pq.push({temp,{nx,ny}});
                }
            }
        }
        return dis[n-1][m-1];
    }
};