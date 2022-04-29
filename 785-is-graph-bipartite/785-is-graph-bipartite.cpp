class Solution {
public:
    bool dfs(vector<vector<int>> &graph, vector<int> &color, int i)
    {
        for(int x:graph[i])
        {
            if(color[x]==color[i])
                return false;
            if(color[x]==-1)
            {
                color[x]=1-color[i];
                if(!dfs(graph, color, x))
                    return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int m=graph.size();
        vector<int>color(m,-1);
        for(int i=0;i<m;i++)
        {
            if(color[i]==-1)
            {
                color[i]=0;
                if(!dfs(graph, color, i))
                    return false;
            }
        }
        return true;
    }
};