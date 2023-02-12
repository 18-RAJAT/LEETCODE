class Solution {
public:
long long result=0;
    int dfs(int node,int parent,unordered_map<int,vector<int>>&adj,int seats)
    {
      int pas=0;
      for(auto &x:adj[node])
      {
          if(x!=parent)
          {
            int p=dfs(x,node,adj,seats);
            pas+=p;
            result+=ceil(p*1.0/seats);
          }
      }
        return 1+pas;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        unordered_map<int,vector<int>>adj;
        for(auto &x:roads)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        dfs(0,-1,adj,seats);
        return result;
    }
};