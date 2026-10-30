class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto& it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        if(k<1)return -1;
        const long long INF=1e18;
        vector<vector<long long>>dist(n,vector<long long>(k+1,INF));
        priority_queue<tuple<long long,int,int>,vector<tuple<long long,int,int>>,greater<>>pq;
        dist[0][1]=0;
        pq.push({0,0,1});
        while(!pq.empty())
        {
            auto [x,y,z]=pq.top();
            pq.pop();
            if(x!=dist[y][z])continue;
            if(y==n-1)return x;
            for(auto& [v,w]:adj[y])
            {
                int nr=(labels[v]==labels[y])?z+1:1;
                if(nr>k)continue;
                long long nd=x+w;
                if(nd<dist[v][nr])
                {
                    dist[v][nr]=nd;
                    pq.push({nd,v,nr});
                }
            }
        }
        return -1;
    }
};