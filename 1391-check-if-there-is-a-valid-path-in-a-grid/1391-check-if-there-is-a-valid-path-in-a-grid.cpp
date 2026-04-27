class Solution{
public:
    bool hasValidPath(vector<vector<int>>&grid){
        int m=grid.size(),n=grid[0].size();
        vector<vector<vector<int>>>dir=
        {
            {},
            {{0,-1},{0,1}},
            {{-1,0},{1,0}},
            {{0,-1},{1,0}},
            {{0,1},{1,0}},
            {{0,-1},{-1,0}},
            {{0,1},{-1,0}}
        };
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0][0]=true;
        while(!q.empty())
        {
            auto [x,y]=q.front();
            q.pop();
            if(x==m-1 && y==n-1)return true;
            for(auto& it:dir[grid[x][y]])
            {
                int nx=x+it[0],ny=y+it[1];

                if(nx<0 || ny<0 || nx>=m || ny>=n || vis[nx][ny])continue;

                for(auto& itr:dir[grid[nx][ny]])
                {
                    if(nx+itr[0]==x && ny+itr[1]==y)
                    {
                        vis[nx][ny]=true;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return false;
    }
};