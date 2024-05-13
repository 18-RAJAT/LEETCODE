class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;++i)
        {
            if(grid[i][0]==0)
            {
                for(int j=0;j<m;++j)
                {
                    grid[i][j]=1-grid[i][j];
                }
            }
        }
        for(int j=0;j<m;++j)
        {
            int cnt=0;
            for(int i=0;i<n;++i)
            {
                if(grid[i][j]==1)
                    cnt++;
            }
            if(cnt*2<n)
            {
                for(int i=0;i<n;++i)
                {
                    grid[i][j]=1-grid[i][j];
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;++i)
        {
            int val=0;
            for(int j=0;j<m;++j)
            {
                val=val*2+grid[i][j];
            }
            ans+=val;
        }
        return ans;
    }
};