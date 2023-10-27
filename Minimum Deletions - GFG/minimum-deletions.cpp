//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int minimumNumberOfDeletions(string S) { 
        // code here
        int n=S.size();
        int dp[n+1][n+1];
        string s=S;
        reverse(s.begin(),s.end());
        for(int i=0;i<=n;++i)
        {
            for(int j=0;j<=n;++j)
            {
                if(i==0 || j==0)
                {
                    dp[i][j]=0;
                }
                else if(S[i-1]==s[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return n-dp[n][n];
    } 
};


//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends