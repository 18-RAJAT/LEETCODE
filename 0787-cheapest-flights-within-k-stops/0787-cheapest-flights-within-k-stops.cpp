
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        auto bellmanFord=[&]()->int
        {
            vector<int>dist(n,INT_MAX);
            dist[src]=0;
            for(int i=0;i<=k;i++)
            {
                vector<int>temp=dist;
                for(auto &x:flights)
                {
                    int u=x[0];
                    int v=x[1];
                    int w=x[2];
                    if(dist[u]!=INT_MAX)
                    {
                        temp[v]=min(temp[v],dist[u]+w);
                    }
                }
                dist=temp;
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