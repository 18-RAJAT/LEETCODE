class Solution {
public:
    int numSquares(int n) {
        
        //puring
        vector<int>dp(n+1,INT_MAX);

        //base case
        dp[0]=0;

        //cache check
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j*j<=i;++j)
            {
                //compute 
                dp[i]=min(dp[i],dp[i-j*j]+1);
            }
        }
        
        //save and return
        return dp[n];
    }
};