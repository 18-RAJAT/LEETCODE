class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n+1);
        /*
            Approach:
            dp[i] denotes the maximum sum that can be obtained by partitioning the array from 0 to i.
            dp[i]=max(dp[i],dp[i-j]+mx*j) where 1<=j<=k and i-j>=0 and mx is the maximum element in the subarray from i-j to i.
            calculate the maximum element in the subarray from i-j to i and update dp[i] accordingly.
            TC:O(n*k),SC:O(n)
        */
        for(int i=1;i<=n;++i)
        {
            int mx=0;
            for(int j=1;j<=k && i-j>=0;++j)
            {
                mx=max(mx,arr[i-j]);
                dp[i]=max(dp[i],dp[i-j]+mx*j);
            }
        }
        return dp[n];
    }
};