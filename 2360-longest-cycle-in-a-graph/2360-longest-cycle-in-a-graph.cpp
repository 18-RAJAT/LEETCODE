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
    ll maximum;
    void dfs(int node,VI &edges,VI &distStart,VI &visited,ll currLength)
    {
        if(!visited[node])
        {
            visited[node]=1;
            distStart[node]=currLength;
            
            if(edges[node]!=-1){dfs(edges[node],edges,distStart,visited,currLength+1);}
            distStart[node]=-1;
        }
        else
        {
            if(distStart[node]!=-1)
            {
                maximum=max(currLength-distStart[node],maximum);
            }
        }
    }
    int longestCycle(vector<int>& edges) {
        maximum=-1;
        ll n=edges.size();
        VI visited(n,0),length(n,-1);
        f1(i,0,n)
        {
            dfs(i,edges,length,visited,0);
        }
        return maximum;
    }
};