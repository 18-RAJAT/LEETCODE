class Solution {
public:
    int directions[8][2]={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
    int dp[4][3][100001];//dp[4]={0,1,2,3},dp[3]={0,1,2},dp[100001]={0,1,2,...,100009}//dp[i][j][k] means the number of ways to reach (i,j) in k steps 100001 is the maximum number of steps
    int dfs(int i,int j,int k,int n)
    {
        //corner case
        if(i<0 || i>=4 || j<0 || j>=3 || (i==3 && (j==0 || j==2)))//if the knight is out of the board or in the corner of the board
        {
            return 0;
        }
        //base+prune
        if(k==n)
        {
            return 1;
        }
        int &ans=dp[i][j][k];
        if(~ans)
        {
            return ans;
        }
        ans=0;
        for(int l=0;l<8;++l)
        {
            ans=(ans+dfs(i+directions[l][0],j+directions[l][1],k+1,n))%1000000007;//add the number of ways to reach (i+directions[l][0],j+directions[l][1]) in k+1 steps
        }
        return ans;
        assert(~dp[i][j][k] && dp[i][j][k]>=0);
    }
    int knightDialer(int n) {
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=0;i<4;++i)//i is the row number
        {
            for(int j=0;j<3;++j)//j is the column number
            {
                if(i==3 && (j==0 || j==2))//if the knight is in the corner of the board then we can't move to any other cell from this cell so we skip this cell and move to the next cell in the board
                {
                    continue;
                }
                ans=(ans+dfs(i,j,1,n))%1000000007;//add the number of ways to reach (i,j) in 1 step to the answer
            }
        }
        return ans;
    }
};