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
typedef queue<int> QI;
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
    void dfs(VII& adj,VI& visited,int n)
    {
        visited[n]=1;
        for(auto it:adj[n])
        {
            if(visited[it]==0)
            {dfs(adj,visited,it);}
        }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& res) {
        // SETI st;
        // //int ct=0,tp=0;bool f=true;
        // int x=edges.size(),y=edges[0].size();
        // f1(i,0,x)
        // {
        //     f1(j,0,y)
        //     {
        //         st.insert(edges[i][j]);
        //     }
        // }
        // sort(res.begin(),res.end());
        // int ct=0,tp=0;
        // for(auto&it:st){if(tp==0){tp++;continue;}
        // bool f=true;
        // f1(j,0,res.size()){if(it==res[j]){f=false;}}
        // if(f){ct++;}}
        // return ct;
        int m=res.size();int result=0;
        VVI adj(n);
        for(auto it:edges)
        {
            adj[it[0]].PB(it[1]);
            adj[it[1]].PB(it[0]);
        }
        VI visited(n,0);
        for(auto it:res)visited[it]=1;
        dfs(adj,visited,0);
        
        for(auto it:visited)
        result=result+it;
        result=result-m;
        return result;
    }
};