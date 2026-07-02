class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size(),m=grid[0].size();
        queue<pair<int,pair<int,int>>>q;
        int check=health-grid[0][0];
        if(check<=0)return false;
        q.push({check,{0,0}});
        vector<vector<int>>ar(n,vector<int>(m,-1));
        ar[0][0]=check;
        int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
        while(!q.empty())
        {
            int cur=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            if(x==n-1 && y==m-1)return true;
            for(int i=0;i<4;++i)
            {
                int nx=x+dx[i],ny=y+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m)
                {
                    int nh=cur-grid[nx][ny];
                    if(nh>=1 && nh>ar[nx][ny])
                    {
                        ar[nx][ny]=nh;
                        q.push({nh,{nx,ny}});
                    }
                }
            }
        }
        return false;
    }
};