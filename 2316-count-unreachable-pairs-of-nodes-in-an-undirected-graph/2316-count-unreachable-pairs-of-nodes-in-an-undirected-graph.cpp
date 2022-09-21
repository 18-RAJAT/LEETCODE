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
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<bool> vb;
typedef vector<vector<string>> VVS;
typedef vector<PII> VIII;
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
    void dfs(ll i,vi adj[],vb &visited,int &temp)
    {
        temp+=1;
        visited[i]=true;
        for(auto it:adj[i])
        {
            if(visited[it]==0){dfs(it,adj,visited,temp);}
        }
    }
    long long countPairs(int n,vii &edges) {
        ll answer=0;
        ll m=edges.size();
        vi adj[n];
        f1(i,0,m)
            adj[edges[i][0]].pb(edges[i][1]),adj[edges[i][1]].pb(edges[i][0]);
        vb visited(n,false);
        ll current=n;
        f1(i,0,n)
        {
            int temp=0;
            if(visited[i]==0)
            {
                dfs(i,adj,visited,temp);
                current=current-temp;
                answer+=current*temp;
            }
        }
        return answer;
    }
};