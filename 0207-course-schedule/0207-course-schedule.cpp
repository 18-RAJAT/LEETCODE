class Solution {
public:
    int topoSort(int node,vector<int>& visited,vector<int>& topo,vector<int>adj[])
    {
        visited[node]=1;
        topo[node]=1;
        for(auto& it:adj[node])
        {
            if(!visited[it])
            {
                if(topoSort(it,visited,topo,adj))return true;
            }
            else if(topo[it])return true;
        }
        topo[node]=0;
        return 0;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        for(int i=0;i<prerequisites.size();++i)
        {
            int u=prerequisites[i][1],v=prerequisites[i][0];
            adj[u].push_back(v);
        }
        vector<int>visited(numCourses,0),topo(numCourses,0);
        for(int i=0;i<numCourses;++i)
        {
            if(!visited[i])
            {
                if(topoSort(i,visited,topo,adj))return 0;
            }
        }
        return 1;
    }
};