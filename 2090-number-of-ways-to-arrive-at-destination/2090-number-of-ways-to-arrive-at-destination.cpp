class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long,long long>>g[n];
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<>>q;
        vector<long long>d(n,LONG_MAX),w(n,0);
        int mod=1e9+7;
        for(auto& r:roads)
        {
            g[r[0]].push_back({r[1],r[2]});
            g[r[1]].push_back({r[0],r[2]});
        }
        q.push({0,0});
        d[0]=0;
        w[0]=1;
        while(!q.empty())
        {
            auto [c,u]=q.top();
            q.pop();
            for(auto& [v,cost]:g[u])
            {
                if(d[v]>c+cost)
                {
                    d[v]=c+cost;
                    q.push({d[v],v});
                    w[v]=w[u]%mod;
                }
                else if(d[v]==c+cost)w[v]=(w[v]+w[u])%mod;
            }
        }
        return w[n-1]%mod;
    }    
};