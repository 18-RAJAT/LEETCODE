class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<vector<int>>adj(n);
        vector<int>cost(n,INT_MAX);
        for(auto& x:edges)
        {
            int u=x[0],v=x[1],w=x[2];
            adj[u].push_back(v);
            adj[v].push_back(u);
            cost[u]&=w;
            cost[v]&=w;
        }
        queue<int>q;
        vector<int>grp(n,-1);
        for(int i=0;i<n;++i)
        {
            if(grp[i]==-1)
            {
                grp[i]=i;
                q.push(i);
                while(!q.empty())
                {
                    int u=q.front();
                    q.pop();
                    cost[i]&=cost[u];
                    for(int v:adj[u])
                    {
                        if(grp[v]==-1)
                        {
                            grp[v]=i;
                            q.push(v);
                        }
                    }
                }
            }
        }
        vector<int>res;
        for(auto& x:query)
        {
            int s=x[0],t=x[1];
            if(s==t)res.push_back(0);
            else res.push_back(grp[s]==grp[t]?cost[grp[s]]:-1);
        }
        return res;
    }
};