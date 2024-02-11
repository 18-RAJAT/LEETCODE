class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int dp[70][70][70];
        fill(&dp[0][0][0],&dp[0][0][0]+70*70*70,-1);
        function<int(int,int,int)>dfs=[&](int row,int column1,int column2)->int
        {
            if(column1<0 || column1>=grid[0].size() || column2<0 || column2>=grid[0].size())
            {
                return 0;
            }
            int &res=dp[row][column1][column2];
            if(~res)
            {
                return res;
            }
            int ans=0;
            ans+=grid[row][column1]+grid[row][column2];
            if(column1==column2)
            {
                ans-=grid[row][column1];
            }
            if(row!=grid.size()-1)
            {
                int mxx=0;
                for(int j1=column1-1;j1<=column1+1;++j1)
                {
                    for(int j2=column2-1;j2<=column2+1;++j2)
                    {
                        mxx=max(mxx,dfs(row+1,j1,j2));
                    }
                }
                ans+=mxx;
            }
            return dp[row][column1][column2]=ans;
        };
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                for(int k=0;k<m;++k)
                {
                    dp[i][j][k]=-1;
                }
            }
        }
        return dfs(0,0,m-1);
    }
};