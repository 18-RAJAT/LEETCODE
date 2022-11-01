class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        vector<int>dp(cols,-1);
        for(int c=0,i,j;c<cols;++c) 
        {
            for(i=0,j=c;i<rows;++i) 
            {
                if (grid[i][j]==1 and j<cols-1 and grid[i][j+1]==1)
                {
                    j++;
                }
                else if (grid[i][j]==-1 and j>0 and grid[i][j-1]==-1) 
                {
                    j--;
                }
                else
                {
                    break;
                }
            }
            if(i==rows) 
            {
                dp[c]=j;
            }
        }
        return dp;
    }
};