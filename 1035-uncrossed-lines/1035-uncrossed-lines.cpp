class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int** dp=new int*[n+1];
        
        for(int i=0;i<=n;++i)
        {
            dp[i]=new int[m+1];
        }
        //base
        for(int i=0;i<=n;++i)
        {
            dp[i][0]=0;
        }
        for(int j=0;j<=m;++j)
        {
            dp[0][j]=0;
        }
        
        //dp recurr
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                // pruning
                if(nums1[i-1]==nums2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max<int>(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int ans=dp[n][m];
        
        //mem free
        for(int i=0;i<=n;++i)
        {
            delete[] dp[i];
        }
        delete[] dp;
        return ans;
    }
};