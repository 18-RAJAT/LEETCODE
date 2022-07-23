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

class Solution {
public:
    void dfs(mvi&adj,int current,vector<int>&visited)
{
    visited[current]=1;//initially the value is true 
        for(auto it:adj[current])
            if(visited[it]==0)//false
                dfs(adj,it,visited);//dfs call
}
    int makeConnected(int n,VII& connections) {
        VI visited(n,0);
        map<int,vector<int>>adj;//connections
        
        //Creating a adjacency lsit
        int edges=0;
        for(int i=0;i<connections.size();++i)
        {
            //undirected list
            adj[connections[i][0]].pb(connections[i][1]);
            adj[connections[i][1]].pb(connections[i][0]);
            edges++;
        }
        
        //Now finding the number of components are connected
        int components=0;
        ff(a,b)//traverse all
        if(visited[i]==0)//false case
        {
            components++;//inc one by one and  checking all the components
            dfs(adj,i,visited);//again dfs call
        }
        
        //Count the no of edges
        //When no of edges are less then MST then return -1
        if(edges<n-1)return -1;
        
        //getting and count the redundant edges
        //Redundant edges-graph with n nodes and we only need n-1 edges to make all the nodes are connected and all other are remaining are redundant(MST)
        int redundant=edges-((n-1)-(components-1));//Count the redundant edges
        if(redundant>=(components-1))//check and if we can join or not and if we are join the edges or components using redundant edges
            return components-1;
        
        return -1;//If all the edges are connected
    }
};