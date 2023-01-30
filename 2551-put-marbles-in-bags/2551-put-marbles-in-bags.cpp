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
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

class Solution {
public:
    long long putMarbles(vector<int>& w, int k) {
        ll n=w.size();
        if(k==1 or k==n)
        {
            return 0;
        }
        VI a;
        ll mn=0,mx=0;
        f1(i,0,n-1)
        {
            a.pb(w[i]+w[i+1]);
        }
        sort(a.begin(),a.end());
        ll m=a.size();
        f1(i,0,k-1)
        {
            mn+=a[i];
            mx+=a[m-i-1];
        }
        ll res=abs(mn-mx);
        return res;
    }
};