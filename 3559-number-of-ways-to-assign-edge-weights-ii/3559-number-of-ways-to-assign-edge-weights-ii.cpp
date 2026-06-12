class Solution {
public:
    vector<int>assignEdgeWeights(vector<vector<int>>& edges,vector<vector<int>>& queries) {
        int n=edges.size()+1;
        vector<vector<int>>g(n+1);
        for(auto& it:edges)
        {
            int u=it[0],v=it[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int res=log2(n)+1;
        vector<vector<int>>par(n+1,vector<int>(res));
        vector<int>dep(n+1);
        queue<int>q;
        q.push(1);
        dep[1]=0;
        par[1][0]=0;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(auto& it:g[u])
            {
                if(it==par[u][0])continue;
                par[it][0]=u;
                dep[it]=dep[u]+1;
                q.push(it);
            }
        }
        for(int i=1;i<res;++i)
        {
            for(int j=1;j<=n;++j)
            {
                par[j][i]=par[par[j][i-1]][i-1];
            }
        }
        auto recur=[&](int u,int v)
        {
            if(dep[u]<dep[v])swap(u,v);
            int diff=dep[u]-dep[v];
            for(int i=0;i<res;++i)
            {
                if(diff&(1<<i))u=par[u][i];
            }
            if(u==v)return u;
            for(int i=res-1;~i;--i)
            {
                if(par[u][i]!=par[v][i])u=par[u][i],v=par[v][i];
            }
            return par[u][0];
        };
        vector<int>ar(n+1,1);
        for(int i=1;i<=n;++i)ar[i]=(ar[i-1]*2LL)%1000000007;
        vector<int>ans;
        for(auto& it:queries)
        {
            int u=it[0],v=it[1],w=recur(u,v),tot=dep[u]+dep[v]-2*dep[w];
            if(tot==0)ans.push_back(0);
            else ans.push_back(ar[tot-1]);
        }
        return ans;
    }
};