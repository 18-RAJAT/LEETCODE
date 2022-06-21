class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dis) {
        vector<vector<int>>adj(n+1);
        for(auto it:dis)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>color(n+1,-1);
        for(int i=0;i<n;++i)
        {
            if(color[i]==-1){if(!bipart(i,color,adj))return false;}
        }
        return true;
    }
    
    bool bipart(int i,vector<int>&color,vector<vector<int>>&adj)
    {
        queue<int>q;q.push(i);
        color[i]=1;
        while(!q.empty())
        {
            int u=q.front();q.pop();
            for(auto it:adj[u])
            {
                if(color[it]==-1)
                {
                    color[it]=1-color[u];q.push(it);
                }
                else if(color[it]==color[u]){return false;}
            }
        }
        return true;
    }
};
