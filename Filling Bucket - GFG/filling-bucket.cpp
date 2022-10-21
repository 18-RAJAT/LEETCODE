//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int fillingBucket(int n) {
        if(n<=1)
        {
            return n;
        }
        int dp[n];
        memset(dp,0,sizeof(dp));
        dp[1]=1,dp[2]=2;
        for(int i=3;i<=n;++i)
        {
            dp[i]=(dp[i-1]+dp[i-2])%100000000;
        }
        return dp[n];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends