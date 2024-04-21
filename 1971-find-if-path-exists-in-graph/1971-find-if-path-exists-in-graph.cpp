class Solution {
public:
    void dfs(int source,vector<vector<int>>& adj,vector<bool>& visited)
    {
        visited[source]=true;
        for(auto& it:adj[source])
        {
            if(visited[it])
            {
                continue;
            }
            else
            {
                dfs(it,adj,visited);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        for(auto& it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool>visited(n);
        dfs(source,adj,visited);
        return(visited[destination]?true:false);
    }
};