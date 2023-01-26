
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        auto bellmanFord=[&]()->int
        {
            vector<int>dist(n,INT_MAX);
            dist[src]=0;//initial point
            for(int i=0;i<=k;i++)
            {
                vector<int>dist1=dist;
                for(auto &edge:flights)
                {
                    int u=edge[0];
                    int v=edge[1];
                    int w=edge[2];
                    if(dist[u]!=INT_MAX)
                    {
                        dist1[v]=min(dist1[v],dist[u]+w);
                    }
                }
                dist=dist1;
            }
            if(dist[dst]==INT_MAX)
            {
                return -1;
            }
            else
            {
                return dist[dst];
            }
        };
        return bellmanFord();
    }
};