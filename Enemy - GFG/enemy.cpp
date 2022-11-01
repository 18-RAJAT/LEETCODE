//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        int largestArea(int n,int m,int k, vector<vector<int>> &a)
{
    if(k==0) return n*m;

    unordered_set<int> x, y;
    for(int i=0; i<k; i++) {
        x.insert(a[i][0]);
        y.insert(a[i][1]);
    }
    x.insert(n+1);
    y.insert(m+1);

    int r = 0, c = 0, temp = 0;
    for(int i=1; i<=n+1; i++) {
        if(x.find(i) == x.end()) temp++;
        else {
            r = max(temp, r);
            temp = 0;
        }
    }

    temp = 0;
    for(int i=1; i<=m+1; i++) {
        if(y.find(i) == y.end()) temp++;
        else {
            c = max(temp, c);
            temp = 0;
        }
    }
    return (r*c);
}
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int k;
        cin>>k;
        vector<vector<int>> e(k,vector<int>(2));
        for(int i=0;i<k;i++)
            cin>>e[i][0]>>e[i][1];
        Solution a;
        cout<<a.largestArea(n,m,k,e)<<endl;
    }
    return 0;
}
// } Driver Code Ends