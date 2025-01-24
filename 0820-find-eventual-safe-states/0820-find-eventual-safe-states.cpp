class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,0),dis(n,0);
        vector<int>adj[n];
        for(int i=0;i<n;++i)
        {
            for(auto& it:graph[i])
            {
                adj[it].push_back(i);
                dis[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;++i)
        {
            if(dis[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty())
        {
            int node=q.front();
            ans.push_back(node);
            q.pop();
            for(auto& it:adj[node])
            {
                dis[it]--;
                if(dis[it]==0)
                {
                    q.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};