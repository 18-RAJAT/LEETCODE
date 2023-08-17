class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>ans(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(auto d:dir)
            {
                int nx=x+d.first;
                int ny=y+d.second;
                if(nx>=0 && nx<n && ny>=0 && ny<m)
                {
                    if(ans[nx][ny]>ans[x][y]+1)
                    {
                        ans[nx][ny]=ans[x][y]+1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return ans;
    }
};