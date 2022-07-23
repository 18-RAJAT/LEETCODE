#define ll long long
typedef vector<pair<int,int>> vv;
typedef pair<int, int> PII;
typedef pair<int,int> PAIR;
typedef vector<int> VI;
typedef vector<vector<int>> VII;
typedef vector<string> VS;
typedef vector<PII> VIII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef unordered_map<char,int> MPC;
typedef map<int,vector<int>> mvi;
typedef set<int> SETI;
typedef multiset<int> MSETI;
#define ff(a,b) for(int i=0;i<n;++i)
#define pb push_back
#define PB pop_back

class Solution {
public:
    void dfs(VII&graph,VII&answer,VI&adj,int u)
    {
        adj.pb(u);
        if(u==graph.size()-1){answer.pb(adj);}
        else
            for(auto it:graph[u])
            dfs(graph,answer,adj,it);
            adj.PB();
    }
    vector<vector<int>> allPathsSourceTarget(VII& graph) {
        VII answer;VI adj;
        dfs(graph,answer,adj,0);
        return answer;
    }
};