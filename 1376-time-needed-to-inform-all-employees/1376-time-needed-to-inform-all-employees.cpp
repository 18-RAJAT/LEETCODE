class Solution {
public:
    int dfs(int i,vector<vector<int>>&adj,vector<int>&manager,vector<int>&info)
    {
        // if(headID==0)return 0;
        int count=0;
        for(auto it:adj[i])
            count=max(count,dfs(it,adj,manager,info));
        return count+info[i];
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& info) {
        vector<vector<int>>adj(n);
        for(int i=0;i<n;++i)
        {
            if(i!=headID)
            {adj[manager[i]].push_back(i);}
        }
        return dfs(headID,adj,manager,info);
    }
};