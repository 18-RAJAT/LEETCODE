class Solution {
public:
    void dfs(vector<vector<int>>&graph,vector<vector<int>>&answer,vector<int>&adj,int u)
    {
        adj.push_back(u);
        if(u==graph.size()-1)
        {
            answer.push_back(adj);
        }
        else
        {
            for(auto it:graph[u])
            {
                dfs(graph,answer,adj,it);adj.pop_back();
            }
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>answer;
        vector<int>adj;
        dfs(graph,answer,adj,0);
        return answer;
    }
};