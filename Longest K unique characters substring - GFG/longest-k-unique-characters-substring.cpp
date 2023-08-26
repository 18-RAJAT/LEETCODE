//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        unordered_map<char,int> mp;
        int i=0,j=0,n=s.size(),m=-1,p=0;
        while(j<n){
            while(p > k){
                mp[s[i]]--;
                if(!mp[s[i]]) p--;
                i++;
            }
            //if(p == k) m=max(m,j-i);
            if(!mp[s[j]]) p++;
            mp[s[j]]++;j++;
            if(p == k) m=max(m,j-i);
        }
        return m;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends