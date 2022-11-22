#define f1(i,s,e) for(long long int i=s;i<e;i++)
#define ff1(i,s,e) for(long long int i=s;i>=e;--i)
#define For1(i,n) (long long int i=0;i<n+1;++i)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)

class Solution {
public:
    int numSquares(int n) {
        // int dp[n+1];
        // memset(dp,INT_MAX,sizeof(dp));
        vector<int>dp(n+1,INT_MAX);
        
        dp[0]=0;
        cf(i,1,n)
        {
            // long long int x=sqrt(n);
            // cf(j,2,x)
            for(int j=1;j*j<=i;j++)
            {
                dp[i]=min(dp[i],dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};