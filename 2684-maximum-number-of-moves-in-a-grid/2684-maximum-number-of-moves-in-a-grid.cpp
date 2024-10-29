class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        vector<vector<int>>v(grid.size(),vector<int>(grid[0].size(),0));
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<grid.size();++i)
        {
            q.push({0,{i,0}});
        }
        int ans=0;
        while(!q.empty())
        {
            int x=q.front().second.first, y=q.front().second.second,F=q.front().first;
            q.pop();
            ans=max(ans,F);
            if(x>0 && y<grid[0].size()-1 && !v[x-1][y+1] && grid[x][y]<grid[x-1][y+1])
            {
                v[x-1][y+1]=1;
                q.push({F+1,{x-1,y+1}});
            }
            if(y<grid[0].size()-1 && !v[x][y+1] && grid[x][y]<grid[x][y+1])
            {
                v[x][y+1]=1;
                q.push({F+1,{x,y+1}});
            }
            if(x<grid.size()-1 && y<grid[0].size()-1 && !v[x+1][y+1] && grid[x][y]<grid[x+1][y+1])
            {
                v[x+1][y+1]=1;
                q.push({F+1,{x+1,y+1}});
            }
        }
        return max<int>(0LL,ans);
    }
};