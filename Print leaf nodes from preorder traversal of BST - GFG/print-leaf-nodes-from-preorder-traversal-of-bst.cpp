//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
         vector <int> ans;
    void solve(int arr[] , int l , int h){
        
        if(l==h)
        {
            ans.push_back(arr[l]); 
            return;
        }
        
        if(l>h)
            return;
            
        int ind =l+1;
        while(ind <= h and arr[ind] < arr[l])
            ind++;

        solve(arr , l+1 , ind-1);
        solve(arr , ind , h);
    }
  
    vector<int> leafNodes(int arr[],int N) 
    {
        // code here
        solve(arr , 0 , N-1);
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends