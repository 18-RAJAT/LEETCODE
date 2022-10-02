// class Solution {
// public:
//     int solve(int n,int k,int target)
//     {
        
//         if(target<0) return 0;
//         if(target==0 and n!=0) return 0;
//         if(target!=0 and n==0) return 0;
//         if(target==0 and n==0) return 1;
       
//         int ans=0;
//         for(int i=1;i<=k;++i)
//         {
//             ans=(ans+solve(n-1,k,target-i))%1000000007;
//         }
//         return ans;
//     }
//     int numRollsToTarget(int n, int k, int target) 
//     {
//         return solve(n,k,target);
//     }
// };


class Solution {
public:
    int dp[31][1001];
    int solve(int n,int k,int target)
    {
        
        if(target<0) return 0;
        if(target==0 and n!=0 or target!=0 and n==0) return 0;
        if(target==0 and n==0) return 1;
        if(dp[n][target]!=-1) return dp[n][target];
        int ans=0;
        for(int i=1;i<=k;++i)
        {
            ans=(ans+solve(n-1,k,target-i))%1000000007;
        }
        return dp[n][target]=ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(n,k,target);
    }
};