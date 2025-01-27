class Solution{
public:
    void dfs(unordered_map<int,vector<int>>&adj,vector<int>&vis,int node){
        vis[node]=1;
        for(auto& it:adj[node])
        {
            if(!vis[it])dfs(adj,vis,it);
        }
    }
    vector<bool> checkIfPrerequisite(int numCourses,vector<vector<int>>&prerequisites,vector<vector<int>>&queries){
        unordered_map<int,vector<int>>adj;
        vector<bool>ans;
        vector<vector<int>>arr(numCourses,vector<int>(numCourses,-1));
        for(auto& it:prerequisites)
        {
            int u=it[0],v=it[1];
            adj[u].push_back(v);
        }
        for(int i=0;i<queries.size();++i)
        {
            if(arr[queries[i][0]][queries[i][1]]==-1)
            {
                vector<int>vis(numCourses,0);
                dfs(adj,vis,queries[i][0]);
                arr[queries[i][0]]=vis;
            }
            ans.push_back(arr[queries[i][0]][queries[i][1]]);
        }
        return ans;
    }
};