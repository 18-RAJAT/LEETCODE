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
typedef vector<bool> VB;
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
typedef queue<int> QUE;
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
    int minReorder(int n, vector<vector<int>>& connections) {
        QUE q;int result=0;
        VB visited(n,false);
        q.push(0);
        VII a(n),b(n);
        for(auto it:connections)
        {
            a[it[0]].pb(it[1]);
            b[it[1]].pb(it[0]);
        }
        visited[0]=true;
        while(!q.empty())
        {
            int store=q.front();q.pop();
            for(auto it:a[store])
            {
                if(!visited[it])
                {q.push(it);result++;visited[it]=true;}
            }
            
            for(auto it:b[store])
            {
                if(!visited[it])
                {q.push(it);visited[it]=true;}
            }
        }
        return result;
    }
};