class Solution {
public:
    vector<int> topoSort(int n,vector<vector<int>>& adj,vector<int>& in)
    {
        vector<int>topo;
        queue<int>q;
        for(int i=0;i<n;++i)
        {
            if(in[i]==0)q.push(i);
        }
        while(!q.empty())
        {
            int F=q.front();
            q.pop();
            topo.push_back(F);
            for(auto& it:adj[F])
            {
                in[it]--;
                if(in[it]==0)q.push(it);
            }
        }
        if(topo.size()!=n)return {};
        return topo;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>in(numCourses,0);
        for(auto& it:prerequisites)
        {
            adj[it[1]].push_back(it[0]);
            in[it[0]]++;
        }
        return topoSort(numCourses,adj,in);
    }
};