//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        set<string> input;
        for(int i=0; i<n; i++){
            input.insert(contact[i]);
        }
        n = input.size();
        int s_size = s.size();
        vector<vector<string>> ans(s.size(), vector<string>());
        for(int j= s_size -1; j>=0; j--)
        {
            bool value = true;
            set<string>::iterator itr;
            for (itr = input.begin(); itr != input.end(); itr++)
            {
                string cur = *(itr);
                if(cur.find(s)==0)
                {
                    value = false;
                    ans[j].push_back(cur);
                }
            }
            if(value){
                ans[j].push_back("0");
            }
            s.pop_back();
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends