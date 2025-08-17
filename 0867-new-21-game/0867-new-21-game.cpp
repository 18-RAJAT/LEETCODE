class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k==0 || n>=k+maxPts)return 1.0;
        vector<double>dp(n+1,0.0);
        dp[0]=1.0;
        double res=1.0,ans=0.0;
        for(int i=1;i<=n;++i)
        {
            dp[i]=res/(double)maxPts;
            (i<k)?res+=dp[i]:ans+=dp[i];
            if(i-maxPts>=0)res-=dp[i-maxPts];
        }
        return ans;
    }
};