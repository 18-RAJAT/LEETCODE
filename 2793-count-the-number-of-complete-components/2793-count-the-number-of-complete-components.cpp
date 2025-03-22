class Solution {
public:
    void bfs(int node,vector<vector<int>>& adj,vector<int>& ar,vector<int>& vis,int parent=-1)
    {
        queue<int>q;
        q.push(node);
        vis[node]=1;
        while(!q.empty())
        {
            int n=q.front();
            q.pop();
            ar.push_back(n);
            for(auto& it:adj[n])
            {
                if(!vis[it])
                {
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto& it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;++i)
        {
            if(!vis[i])
            {
                vector<int>ar;
                bfs(i,adj,ar,vis);
                int ok=1;
                for(auto& it:ar)
                {
                    if(adj[it].size()!=ar.size()-1)
                    {
                        ok=0;
                        break;
                    }
                }
                if(ok)ans++;
            }
        }
        return ans;
    }
};