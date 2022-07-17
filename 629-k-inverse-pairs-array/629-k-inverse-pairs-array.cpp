class Solution {
    long long mod=1000000007;
public:
    int kInversePairs(int n, int k) {
        vector<int> dp0(k+1),dp1(k+1);
        dp0[0]=dp1[0]=1;
        for (int i=1;i<=n;++ i)
        {
            for (int j=1;j<=k;++j)
                dp1[j]=(dp1[j-1]+dp0[j]+mod-(j-i>=0?dp0[j-i]:0))%mod; 
            swap(dp0,dp1);
        }
        return dp0.back();
    }
};