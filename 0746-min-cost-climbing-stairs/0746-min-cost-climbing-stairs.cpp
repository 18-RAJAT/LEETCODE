class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp=cost;

        for(int i=2;i<n;++i)
        {dp[i]=dp[i]+min(dp[i-1],dp[i-2]);}
        return min(dp[n-1],dp[n-2]);
    }
};


// class Solution {
// public:
//     int useMemo(vector<int>&cost,int n)
//     {
//         int m=cost.size();
//         int dp[m+1];int mn;
//         memset(dp,0,sizeof(dp));
//         for(int i=2;i<m;++i)
//         {
//             dp[i]=dp[i]+min(dp[i-1],dp[i-2]);
//         }
//         // int mn=*min_element(dp[n-1],dp[n-2]);
//         return mn=min(dp[m-1],dp[m-2]);
//     }
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n;
//         useMemo(cost,n);
//         return true;
//     }
// };