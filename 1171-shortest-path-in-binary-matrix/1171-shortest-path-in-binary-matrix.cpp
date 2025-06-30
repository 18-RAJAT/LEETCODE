class Solution {
public:
    vector<vector<int>>dir={{1,0},{-1,0},{0,-1},{0,1},{1,1},{-1,-1},{-1,1},{1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>ans(n,vector<int>(m,INT_MAX));
        if(grid[0][0]==0)
        {
            q.push({1,{0,0}});
            ans[0][0]=1;
        }
        while(!q.empty())
        {
            auto F=q.front().second.first;
            auto S=q.front().second.second;
            int dist=q.front().first;
            q.pop();
            for(auto& it:dir)
            {
                int x=it[0],y=it[1];
                int ni=F+x,nj=S+y;
                if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj]==0 && dist+1<ans[ni][nj])
                {
                    ans[ni][nj]=dist+1;
                    q.push({dist+1,{ni,nj}});
                }
            }
        }
        if(ans[n-1][m-1]==INT_MAX)return -1;
        return ans[n-1][m-1];
    }
};