class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int ans=INT_MAX;
        vector<vector<pair<int,int>>>graph(n+1);
        for(auto& it:roads)
        {
            graph[it[0]].push_back(make_pair(it[1],it[2]));
            graph[it[1]].push_back(make_pair(it[0],it[2]));
        }
        int visited[n+1];
        memset(visited,0,sizeof(visited));
        
        queue<int>q;
        q.push(1);
        visited[1]=1;
        
        while(not q.empty())
        {
            auto node=q.front();
            q.pop();
            
            for(auto& [src,dist]:graph[node])
            {
                ans=min(ans,dist);
                
                if(visited[src]==0)
                {
                    visited[src]=1;
                    q.push(src);
                }
            }
        }
        return ans;
    }
};