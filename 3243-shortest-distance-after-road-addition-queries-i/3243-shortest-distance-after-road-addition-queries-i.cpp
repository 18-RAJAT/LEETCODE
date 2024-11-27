class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<pair<int,int>>>adj=init(n);
        vector<int>ans;
        for(auto& it:queries)
        {
            add(adj,it[0],it[1]);
            int path=find_path(adj,n,0,n-1);
            ans.push_back(path);
        }
        return ans;
    }
private:
    vector<vector<pair<int,int>>>init(int n)
    {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<n-1;++i)
        {
            adj[i].push_back({i+1,1});
        }
        return adj;
    }
    void add(vector<vector<pair<int,int>>>& adj,int u,int v)
    {
        adj[u].push_back({v,1});
    }
    int find_path(vector<vector<pair<int,int>>>& adj,int n,int start,int end)
    {
        vector<int>dist(n,INT_MAX);
        dist[start]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.emplace(0,start);
        
        while(!pq.empty())
        {
            int F_dist=pq.top().first;
            int S_dist=pq.top().second;
            pq.pop();
            if(F_dist>dist[S_dist])continue;
            
            for(auto& it:adj[S_dist])
            {
                int take1=it.first;
                int take2=it.second;
                int newDist=F_dist+take2;
                
                if(newDist<dist[take1])
                {
                    dist[take1]=newDist;
                    pq.emplace(newDist,take1);
                }
            }
        }
        
        return dist[end];
    }
};