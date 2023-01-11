class Solution {
public:
    int dfs(vector<int>adj[],vector<bool>&hasApple,int node,int parent)
    {
        int total=0;
        
        for(auto child:adj[node])
        {
            if(child==parent)
            {
                continue;
            }
            int ct=dfs(adj,hasApple,child,node);
            if(ct>0 or hasApple[child])
            {
                total=2+total+ct;
                // cout<<"Total Move: "<<total<<"\n";
            }
        }
        return total;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int>adj[n];
        
        for(vector<int>&edge:edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int res=dfs(adj,hasApple,0,0);
        return res;
    }
};