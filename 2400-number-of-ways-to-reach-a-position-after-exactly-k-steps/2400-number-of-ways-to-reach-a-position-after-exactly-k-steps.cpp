#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()
const double pi=acos(-1.0);
#define ll long long
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<vector<int>> VII;
typedef vector<string> VS;
typedef vector<vector<string>> VVS;
typedef map<pair<ll,ll>,ll> mpii;
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
#define all(x) sort(x.begin(), x.end())
#define ff(a,b) for(int i=a;i<b;i++)
#define f1(i,s,e) for(long long int i=s;i<e;i++)
#define ff1(pass) for(long long int i=n-2;i>=0;--i)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define FOREACH(n) for(auto it:n)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back

class Solution {
public:
    int solve(int d,int k,VVI &dp)
    {
        if(d>k)return 0;
        if(k==d)return 1;
        
        if(dp[d][k]!=-1)return dp[d][k];
        
        //move right and move left 
        return dp[d][k]=(solve(abs(d+1),k-1,dp)%MOD+solve(abs(d-1),k-1,dp)%MOD)%MOD;
    }
    
    ll numberOfWays(ll startPos, ll endPos, ll k) {
        VVI dp(k+2,VI(k+1,-1));
        int absolute=abs(endPos-startPos);
        if(absolute%2 != k%2)return 0;
        
        int result=solve(absolute,k,dp);
        return result;
    }
};