class Solution {
public:
    void dfs(vector<vector<int>>&grid,int i,int j,int RO=2)
    {
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]==0 or(1<grid[i][j] and grid[i][j]<RO))return;
        grid[i][j]=RO;
        dfs(grid,i+1,j,RO+1);
        dfs(grid,i-1,j,RO+1);
        dfs(grid,i,j+1,RO+1);
        dfs(grid,i,j-1,RO+1);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        // int RO=2;
        int n=grid.size();int m=grid[0].size();
        for(int i=0;i<n;++i)
        {
            // cout<<i;
            for(int j=0;j<m;++j)
            {
                // cout<<j;
                if(grid[i][j]==2){dfs(grid,i,j);}
            }
        }
        int RO=2;
        for(auto &f:grid)
        {
            for(auto &ff:f)
            {
                if(ff==1)return -1;
                //{return 1;}
                // cout<<"1  1"; possible? op->1  11  11  11  11  11  11  11  11  1
                RO=max(RO,ff);
            }
        }
        // cout<<RO;
        // cout<<RO-2;
        return RO-2;
    }
};