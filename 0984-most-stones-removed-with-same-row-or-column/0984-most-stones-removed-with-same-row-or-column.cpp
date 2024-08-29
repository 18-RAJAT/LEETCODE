class Solution {
public:
    void dfs(vector<vector<int>> &adj,int node,vector<int> &vis)
    {
        vis[node]=1;
        for(int i=0;i<adj[node].size();++i)
        {
            if(!vis[adj[node][i]]) dfs(adj,adj[node][i],vis);
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<vector<int>>adj(n);
        unordered_map<int,int>mapx;
        unordered_map<int,int>mapy;

        for(int i=0;i<n;++i)
        {
            if(mapx.count(stones[i][0]))
            {
                adj[i].push_back(mapx[stones[i][0]]);
                adj[mapx[stones[i][0]]].push_back(i);
            }
            else mapx[stones[i][0]]=i;

            if(mapy.count(stones[i][1]))
            {
                adj[i].push_back(mapy[stones[i][1]]);
                adj[mapy[stones[i][1]]].push_back(i);
            }
            else  
            {
                mapy[stones[i][1]]=i;
            }
        }

        vector<int>vis(n,0);
        int res=0;
        for(int i=0;i<n;++i)
        {
            if(!vis[i])
            {
                dfs(adj,i,vis);
                res++;
            }
        }
        return abs(res-n);
    }
};