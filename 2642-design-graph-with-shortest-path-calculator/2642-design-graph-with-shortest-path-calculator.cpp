class Graph {
public:
    vector<pair<int,int>>adj[101];
    Graph(int n, vector<vector<int>>& edges) {
        for(auto& it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
    }
    int dijsktra(int node1,int node2)
    {
        vector<int>dis(101,INT_MAX);
        priority_queue<pair<int,int>>pq;
        pq.push({0,node1});
        dis[node1]=0;
        while(pq.size()!=0)
        {
            auto iter=pq.top();
            pq.pop();
            int cost=iter.first;
            int node=iter.second;
            if(node==node2)
            {
                return -cost;
            }
            if(dis[node]<cost)
            {
                continue;
            }
            for(auto it:adj[node])
            {
                int child=it.first;
                int edW=it.second;
                int tot_dis=edW+dis[node];
                if(tot_dis<dis[child])
                {
                    dis[child]=tot_dis;
                    pq.push({-dis[child],child});
                }
            }
        }
        return dis[node2];
    }
    
    void addEdge(vector<int> edge) {
        int u=edge[0];
        int v=edge[1];
        int ert=edge[2];
        adj[u].push_back({v,ert});
    }
    
    int shortestPath(int node1, int node2) {
        int val=dijsktra(node1,node2);
        if(val==INT_MAX)
        {
            return -1;
        }
        return val;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */