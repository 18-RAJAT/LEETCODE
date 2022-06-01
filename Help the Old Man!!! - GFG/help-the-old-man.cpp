// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

   void toh(int N, int from, int to, int aux, vector<pair<int, int>> &ans)
    {
        if (N == 0)
            return;

        toh(N - 1, from, aux, to, ans);
        ans.push_back({from, to});
        toh(N - 1, aux, to, from, ans);
    }
    vector<int> shiftPile(int N, int n)
    {
        // code here
        vector<pair<int, int>> ans;
        toh(N, 1, 3, 2, ans);
        return {ans[n-1].first, ans[n-1].second};
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, n;
        cin>>N>>n;
        
        Solution ob;
        vector<int> ans = ob.shiftPile(N, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends