// class Solution {
// public:
//     int fib(int n) {

//             //USING RECURSION

//             if(n==0 or n==1){return n;}
//             int subproblem1=fib(n-1);
//             int subproblem2=fib(n-2);
//             return subproblem1+subproblem2;
//     }
// };

  
//USING DP
// class Solution {
// public:
//     int fib(int n) {
//         if(n<2){return n;}int dp[n+1];dp[0]=0,dp[1]=1;
//         for(int i=2;i<=n;++i)
//         {dp[i]=dp[i-1]+dp[i-2];}
//             return dp[n];
//     }
// };



//3rd way
class Solution {
public:
    int fib(int n) {
        if(n<2){return n;}
        int p1=0,p2=1;
        while(--n){int tp=p1+p2;p1=p2;p2=tp;}
        return p2;
    }
};