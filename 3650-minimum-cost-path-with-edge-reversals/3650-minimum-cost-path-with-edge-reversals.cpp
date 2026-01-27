class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adjList(n);
        for(int i=0;i<edges.size();++i)
        {
            adjList[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adjList[edges[i][1]].push_back({edges[i][0],2*edges[i][2]});
        }
        vector<int>cost(n,INT_MAX);
        cost[0]=0;
        set<pair<int,int>>pq;
        pq.insert({0,0});
        while(!pq.empty())
        {
            auto[chk,cur]=*pq.begin();
            pq.erase(pq.begin());
            if(cur==n-1)
            {
                return cost[cur];
            }
            for(auto[v,w]:adjList[cur])
            {
                if(cost[cur]+w<cost[v])
                {
                    pq.erase({cost[v],v});
                    cost[v]=cost[cur]+w;
                    pq.insert({cost[v],v});
                }
            }
        }
        return -1;
    }
};