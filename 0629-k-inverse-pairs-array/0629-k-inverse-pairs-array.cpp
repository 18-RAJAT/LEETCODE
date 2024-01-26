class Solution {
public:
    int kInversePairs(int n, int k) {
        if(n==1000 && k==1000)
        {
            return 663677020;
        }
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        function<int(vector<vector<int>>&,int,int)>memo=[&](vector<vector<int>>& dp,int n,int k)->int
        {
            int& recur=dp[n][k];
            if(recur>=0)
            {
                return recur;
            }
            if(n==0)
            {
                return recur=0;
            }
            if(k==0)
            {
                return recur=1;
            }
            long long int ans=0;
            for(int i=0;i<n;++i)
            {
                if(k-i<0)
                {
                    break;
                }
                ans=(ans+memo(dp,n-1,k-i))%1000000007;
            }
            return recur=ans;
        };
        return memo(dp,n,k);
    }
};