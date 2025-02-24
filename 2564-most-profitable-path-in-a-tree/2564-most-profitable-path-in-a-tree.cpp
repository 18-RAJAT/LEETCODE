class Solution {
public:
    int path(unordered_map<int,vector<int>>& adj,int bob,vector<int>& vis,vector<int>& bobPath)
    {
        bobPath.push_back(bob);
        if(bob==0)return 1;
        vis[bob]=1;
        for(auto& it:adj[bob])
        {
            if(!vis[it] && path(adj,it,vis,bobPath))return 1;
        }
        bobPath.pop_back();
        return 0;
    }
    void update(vector<int>& amount,vector<int>& bobPath)
    {
        for(int i=0;i<bobPath.size()/2;++i)amount[bobPath[i]]=0;
        if(bobPath.size()&1)amount[bobPath[bobPath.size()/2]]/=2;
    }
    void dfs(unordered_map<int,vector<int>>& adj,int node,vector<int>& vis,vector<int>& amount,int cur,int& ans)
    {
        cur+=amount[node];
        if(adj[node].size()==1&&node!=0)
        {
            ans=max(ans,cur);
            return;
        }
        vis[node]=1;
        for(auto& it:adj[node])
        {
            if(!vis[it])dfs(adj,it,vis,amount,cur,ans);
        }
    }
    int mostProfitablePath(vector<vector<int>>& edges,int bob,vector<int>& amount)
    {
        unordered_map<int,vector<int>>adj;
        for(auto& it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int n=edges.size()+1,ans=INT_MIN;
        vector<int>bobPath,vis(n,0);
        path(adj,bob,vis,bobPath);
        update(amount,bobPath);
        vis.assign(n,0);
        dfs(adj,0,vis,amount,0,ans);
        return ans;
    }
};