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
    //deadlock case check(cycle or not)
    bool isCycle(VVI& adj,VI&visited,int current)
{
        int n=adj[current].size();
    // if(visited[current]!=2){return false;}
     if(visited[current]==2){return true;}
        visited[current]=2;
        f1(i,0,n)
            //If we have processed,then we will be skip
            if(visited[adj[current][i]]!=1)
            if(isCycle(adj,visited,adj[current][i])){return true;}
            
            visited[current]=1;
            return false;
}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        VVI adj(numCourses);
        //make adj matrix and directed graph
        int m=prerequisites.size();
        f1(i,0,m)
        
            adj[prerequisites[i][0]].PB(prerequisites[i][1]);//directed
            VI visited(numCourses,0);
            f1(i,0,numCourses)
                
                if(visited[i]==0)
                if(isCycle(adj,visited,i))return false;
        return true;
    }
};