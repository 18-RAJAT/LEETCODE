//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beautySum(string s) {
        // Your code goes here
        int n=s.length();
        int sum=0;
        
        for(int i=0;i<n;++i)
        {
            map<char,int>mp;
            for(int j=i;j<n;++j)
            {
                mp[s[j]]++;
                int mn=INT_MAX;
                int mx=INT_MIN;
                
                for(auto it:mp)
                {
                    if(it.second>mx)
                    {
                        mx=it.second;
                    }
                    if(it.second<mn)
                    {
                        mn=it.second;
                    }
                }
                sum+=abs(mn-mx);
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends