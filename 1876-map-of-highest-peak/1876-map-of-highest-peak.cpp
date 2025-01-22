class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size(),n=isWater[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        vector<vector<int>>ans(m,vector<int>(n,0));
        queue<vector<int>>q;
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(isWater[i][j])
                {
                    q.push({i,j,0});
                    vis[i][j]=1;
                }
            }
        }
        int nx,ny;
        int dir[]={-1,0,1,0,-1};
        while(!q.empty())
        {
            //row,col,dep
            int x=q.front()[0],y=q.front()[1],depth=q.front()[2];
            q.pop();
            for(int i=0;i<4;++i)
            {
                nx=x+dir[i];
                ny=y+dir[i+1];
                if(nx>=0 && ny>=0 && nx<m && ny<n && !vis[nx][ny] && !isWater[nx][ny])
                {
                    vis[nx][ny]=1;
                    ans[nx][ny]=depth+1;
                    q.push({nx,ny,depth+1});
                }
            }
        }
        return ans;
    }
};