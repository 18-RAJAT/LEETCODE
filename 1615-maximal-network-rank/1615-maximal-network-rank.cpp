class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>degree(n);
        vector<vector<bool>>adj(n,vector<bool>(n));
        for(int i=0;i<roads.size();++i)
        {
            auto&it=roads[i];
            degree[it[0]]++;
            degree[it[1]]++;
            adj[it[0]][it[1]]=true;
            adj[it[1]][it[0]]=true;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                ans=max<int>(ans,degree[i]+degree[j]-(adj[i][j]?1:0));
            }
        }
        return ans;
    }
};