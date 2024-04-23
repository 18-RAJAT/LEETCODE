class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>ans;
        if(n==1)
        {
            ans.push_back(0);
            return ans;
        }
        vector<int>degree(n,0);
        vector<vector<int>>adj(n);
        for(auto &edge:edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        queue<int>q;
        for(int i=0;i<n;++i)
        {
            if(degree[i]==1)
            {
                q.push(i);
            }
        }
        while(n>2)
        {
            int size=q.size();
            n-=size;
            for(int i=0;i<size;++i)
            {
                int node=q.front();
                q.pop();
                for(auto &neighbour:adj[node])
                {
                    degree[neighbour]--;
                    if(degree[neighbour]==1)
                    {
                        q.push(neighbour);
                    }
                }
            }
        }
        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};