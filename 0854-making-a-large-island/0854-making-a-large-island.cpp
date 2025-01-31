class Solution {
public:
    void dfs(vector<vector<int>>& grid,int x,int y,int check)
    {
        grid[x][y]=check;
        int n=grid.size();
        for(int k=0;k<4;++k)
        {
            int i=x+dx[k],j=y+dy[k];
            if(i>=0 && i<n && j>=0 && j<n && grid[i][j]==1)
            {
                dfs(grid,i,j,check);
            }
        }
    }
    int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size(),check=2;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(grid[i][j]==1)
                {
                    dfs(grid,i,j,check);
                    check++;
                }
            }
        }
        vector<int>arr(check,0);
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(grid[i][j]>1)arr[grid[i][j]]++;
            }
        } 
        int ans=0;
        for(int i=2;i<check;++i)ans=max(ans,arr[i]);
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(grid[i][j]==0)
                {
                    set<int>s;
                    for(int k=0;k<4;++k)
                    {
                        int x=i+dx[k],y=j+dy[k];
                        if(x>=0 && x<n && y>=0 && y<n && grid[x][y]>1)
                        {
                            s.insert(grid[x][y]);
                        }
                    }
                    int maxi=1;
                    for(auto& it:s)maxi+=arr[it];
                    ans=max(ans,maxi);
                }
            }
        }
        return ans;
    }
};