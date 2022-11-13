#define MP make_pair
#define INF (int)1e9
#define EPS 1e-9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define ll long long
#define all(x) sort(x.begin(), x.end())
#define ff(a,b) for(int i=a;i<b;i++)
#define f1(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define FOREACH(n) for(auto it:n)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<vector<int>> VII;
typedef vector<string> VS;
typedef vector<vector<string>> VVS;
typedef vector<PII> VIII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef priority_queue<pair<int,pair<int,int>>> PQVI;
typedef unordered_map<string,vector<string>> MPSVS;
typedef set<int> SETI;
typedef multiset<int> MSETI;
#define nl endl

class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        int n=s.length();
        // int ct=0;
        f1(i,0,n)
        {
            string word="";
            if(s[i]==' ')
            {
                continue;
            }
            while(s[i]!=' ' and i<s.length())
            {
                word+=s[i];
                ++i;
            }
            // cout<<i<<" ";
            
            st.push(word);
        }
        // int x=st.top();
        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
            
            if(!st.empty())
            {
                // ct++;
                ans+=" ";
            }
            // cout<<ans<<" ";
            
            // cout<<ct<<nl;
        }
        return ans;
    }
};