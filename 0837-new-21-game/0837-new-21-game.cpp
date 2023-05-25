class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k==0 or n>=k+maxPts) 
        {
            return 1.0;
        }
        vector<double>dp(n+1,0.0);
        dp[0]=1.0;
        double window=1.0;
        double ans=0.0;
        for(int i=1;i<=n;++i)
        {
            dp[i]=window/(double)maxPts;
            if(i<k)
            {
                window+=dp[i];
            }
            else
            {
                ans+=dp[i];
            }
            if(i-maxPts>=0)
            {
                window-=dp[i-maxPts];
            }
        }
        return ans;
    }
};