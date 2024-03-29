//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int removals(vector<int>& arr, int k){
        sort(arr.begin(), arr.end());
        int n = arr.size(), cnt = arr.size();
        for(int i = 0; i < n; i++){
            int ind = upper_bound(arr.begin()+i+1, arr.end(), arr[i]+k) - arr.begin();
            cnt = min(cnt, n-ind+i);
        }
        return cnt;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends