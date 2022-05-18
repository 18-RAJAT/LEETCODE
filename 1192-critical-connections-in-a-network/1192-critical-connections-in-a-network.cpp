static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

//---------------------------------------------------------SOLUTION OF USING TARJAN'S ALGORITHM-----------------------------------------------------------------------//

class Solution {
        
        unordered_map<int,vector<int>>adj;//ADJ list
        void dfs(int u,vector<int>& disc,vector<int>& low,vector<int>& parent,vector<vector<int>>& bridges)
        {
                static int time=0;
                disc[u]=low[u]=time;
                time+=1;
                
                for(int v : adj[u])
                {
                        if(disc[v]==-1)//IF v is not visited initially -1
                        {
                                parent[v]=u;
                                dfs(v,disc,low,parent,bridges);
                                low[u]=min(low[u],low[v]);
                                
                                if(low[v]>disc[u]){bridges.push_back(vector<int>({u,v}));}
                        }
                        else if(v!=parent[u])//Check the previous / back edge
                                low[u]=min(low[u],disc[v]);
                }
        }
        
        //Using tarjan's ALGO
        void findbridgesTarjan(int V,vector<vector<int>>& bridges)
        {
                vector<int>disc(V,-1),low(V,-1),parent(V,-1);
                //Using dfs for each component
                for(int i=0;i<V;++i)
                        if(disc[i]==-1){dfs(i,disc,low,parent,bridges);}
        }
        
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        for(int i=0;i<connections.size();++i)//Make adj list
        {
                //Moves of to find the critical connectiosn of the network  
                adj[connections[i][0]].push_back(connections[i][1]);
                adj[connections[i][1]].push_back(connections[i][0]);
        }
            
            vector<vector<int>>bridges; //Stroe all the bridges as a pairs
            //Function call
            findbridgesTarjan(n,bridges);
            return bridges;
    }
};