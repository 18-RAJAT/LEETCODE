// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:

     int dp[505];
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        k++;
        int spc = k;
        memset(dp, -1 , sizeof(dp));
        int ans = f(nums , 0 , k);
        return dp[0];
    } 
       int f(vector<int> nums , int idx ,int spc)
       {
        if(idx >= nums.size()) return 0;
        int org = spc;
        int res = INT_MAX;
        int ans = 0;
        if(dp[idx] != -1) return dp[idx];
        for(int i=idx; i<nums.size()  && spc > nums[i] ; i++ ){
            
            spc-=(nums[i] + 1);
           
            ans = (spc*spc);
            
            
            int k = i == nums.size() - 1 ? 0 : ans + f(nums,  i+ 1 , org) ;
            
            res = min(res , k);
            
           
        }
        return dp[idx] = res;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}  // } Driver Code Ends