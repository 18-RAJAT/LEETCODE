class Solution {
public:
    
    vector<vector<int>>adj;
    vector<int>ans;
    vector<int>dfs(int s,int parent,string& label)
    {
        vector<int>result(26,0);
        //add value in current node
        result[label[s]-'a']++;
        
        for(auto it:adj[s])
        {
            if(it==parent)
            {
                continue;
            }
            vector<int>freq=dfs(it,s,label);
            for(int i=0;i<26;++i)
            {
                result[i]+=freq[i];
            }
        }
        ans[s]=result[label[s]-'a'];
        return result;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string label) {
        ans.resize(n,0);
        adj.resize(n,vector<int>{});
        
        for(auto edge:edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        dfs(0,0,label);
        return ans;
    }
};