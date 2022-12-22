class Solution {
public:
    vector<vector<int>>v;
    vector<int>ct;
    vector<int>ans;
    
    void dfs(int i,int parent=-1)
    {
        for(auto &it:v[i])
        {
            if(it==parent)
            {
                continue;
            }
            dfs(it,i);
            ct[i]+=ct[it];
            ans[i]+=ans[it]+ct[it];
       }
       ct[i]+=1;
    }
    
    void dfs1(int i,int n,int parent=-1)
    {
        for(auto &it:v[i])
        {
            if(it==parent)
            {
                continue;
            }
            ans[it]=ans[i]-ct[it]+n-ct[it];
            
            dfs1(it,n,i);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        v.resize(n);
        for(int i=0;i<n-1;++i)
        {
            v[edges[i][0]].push_back(edges[i][1]);
            v[edges[i][1]].push_back(edges[i][0]);
        }
        ans.resize(n);
        ct.resize(n);
        
        dfs(0);
        dfs1(0,n);
        
        return ans;
    }
};