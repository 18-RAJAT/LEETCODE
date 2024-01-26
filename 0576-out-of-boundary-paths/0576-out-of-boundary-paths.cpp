class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int dp[55][55][55];
        fill(&dp[0][0][0],&dp[0][0][0]+55*55*55,0);
        for(int i=1;i<=maxMove;++i)
        {
            for(int j=0;j<m;++j)
            {
                for(int k=0;k<n;++k)
                {
                    dp[i][j][k]=((long long int)(j==0?1:dp[i-1][j-1][k])+(j==m-1?1:dp[i-1][j+1][k])+(k==0?1:dp[i-1][j][k-1])+(k==n-1?1:dp[i-1][j][k+1]))%1000000007;
                }
            }
        }
        return dp[maxMove][startRow][startColumn]%1000000007;
    }
};