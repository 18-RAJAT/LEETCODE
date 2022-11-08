//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int n;
int64_t s = 0;
class Solution{

  public:
	int minDifference(int arr[], int N)  { 
	    n = N;
	    s = accumulate(arr, arr+N, 0);
	    
	    vector<vector<int>> dp(n, vector<int> (s, -1));
	    int ans = recurse(arr, 0, 0, dp);
	    return ans;
	} 
	
	int recurse(int *arr, int i, int taken, vector<vector<int>> &dp) {
	    if (i == n) {
	        return abs(2 * taken - s);
	    }
	    
	    if (dp[i][taken] != -1) return dp[i][taken];
	    
	    // ch1 : do not take arr[i]
	    int ch1 = recurse(arr, i+1, taken, dp);
	    
	    // ch2 : take arr[i]
	    int ch2 = recurse(arr, i+1, taken + arr[i], dp);
	    
	    return dp[i][taken] = min(ch1, ch2);
	}
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends