class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>>graph(n);
        int ed=edges.size();
        for(int i=0;i<ed;++i)
        {
            graph[edges[i][0]].push_back({edges[i][1],succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue<pair<double,int>>pq;
        pq.push({1.0,start});
        vector<int>visited(n,0);
        vector<double>vals(n,0.0);
        vals[start]=1.0;
        
        while(!pq.empty())
        {
            double currVal=pq.top().first;
            double currNode=pq.top().second;
            pq.pop();
            visited[currNode]=1;
            for(int i=0;i<graph[currNode].size();++i)
            {
                int chkNextNode=graph[currNode][i].first;
                double weight=graph[currNode][i].second;
                
                if(visited[chkNextNode]==0)
                {
                    double next=currVal*weight;
                    if(vals[chkNextNode]<next)
                    {
                        vals[chkNextNode]=next;
                    }
                    pq.push({next,chkNextNode});
                }
            }
        }
        return vals[end]==0.0?0.0:vals[end];
    }
};