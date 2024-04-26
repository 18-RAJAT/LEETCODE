class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int ans=INT_MAX;
        if(n==1)
        {
            return grid[0][0];
        }
        for(int i=n-2;i>=0;--i)
        {
            for(int j=0;j<n;++j)
            {
                int res=INT_MAX;
                for(int x=0;x<n;x++)
                {
                    if(x!=j)
                    {
                        res=min(res,grid[i+1][x]);
                    }
                }
                grid[i][j]+=res;
                if(i==0)
                {
                    ans=min(ans,grid[i][j]);
                }
            }
        }
        return ans;
    }
};