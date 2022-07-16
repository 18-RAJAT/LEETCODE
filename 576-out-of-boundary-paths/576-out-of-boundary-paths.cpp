class Solution {
public:
    int mod=1e9+7;
    int dp[51][51][51];
    int solve(int m,int n,int k,int i,int j)
    {
        if(i<0 or j<0 or i>=m or j>=n){return 1;}
        if(k==0)return 0;
        if(dp[i][j][k]!= -1)return dp[i][j][k];
        
     long long int ans=0;
        ans=(ans%mod+solve(m,n,k-1,i+1,j)%mod+solve(m,n,k-1,i,j+1)%mod 
            +solve(m,n,k-1,i-1,j)% mod+solve(m,n,k-1,i,j-1)% mod)%mod;
        dp[i][j][k]=(ans%mod)%mod;
        return(dp[i][j][k]%mod)%mod;
    }
    int findPaths(int m,int n,int k,int i,int j) {
        memset(dp,-1,sizeof(dp));
        return solve(m,n,k,i,j);
    }
};