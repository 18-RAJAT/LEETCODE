class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);
        queue<int>q;

        for(vector<int>&edge:prerequisites)
        {
            int u=edge[1];
            int v=edge[0];

            adj[u].push_back(v);
            indegree[v]++;

            // cout<<"Degree: "<<indegree[v]<<"\n";
        }
        for(int i=0;i<numCourses;++i)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        
        //topo sort
        while(not q.empty())
        {
            int tp=q.front();
            q.pop();

            for(auto it:adj[tp])
            {
                indegree[it]--;

                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        
        //if indegree of all nodes is 0,then all courses are finished else we will not finish
        for(int i=0;i<numCourses;++i)
        {
            if(indegree[i])
            {
                 return false;
            }
        }
        return true;
    }
};