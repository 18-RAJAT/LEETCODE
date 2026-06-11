class Solution{
public:
    int MOD=1000000007;
    int dfs(int node,vector<int>& vis,vector<vector<int>>& adj)
    {
        vis[node]=1;
        int depth=1;
        for(auto& it:adj[node])
        {
            if(!vis[it])depth=max(depth,1+dfs(it,vis,adj));
        }
        return depth;
    }
    int find(int x,vector<int>& dp,int sum)
    {

        if(x==1)return 1;
        if(~dp[x])return dp[x];
        return dp[x]=((find(x-1,dp,sum+1)%MOD+find(x-1,dp,sum+2))%MOD)%MOD;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>>adj(n+2);
        for(auto& it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n+2,0);
        int dep=dfs(1,vis,adj);
        dep--;
        vector<int>dp(dep+1,-1);
        return find(dep,dp,0);
    }
};