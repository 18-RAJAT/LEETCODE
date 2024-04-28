class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for(auto &e:edges)
        {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<int> count(n,1),res(n,0);
        function<void(int,int)> dfs1=[&](int u,int f)
        {
            for(auto v:g[u])
            {
                if(v==f)
                    continue;
                dfs1(v,u);
                count[u]+=count[v];
                res[u]+=res[v]+count[v];
            }
        };
        function<void(int,int)> dfs2=[&](int u,int f)
        {
            for(auto v:g[u])
            {
                if(v==f)
                    continue;
                res[v]=res[u]-count[v]+n-count[v];
                dfs2(v,u);
            }
        };
        dfs1(0,-1);
        dfs2(0,-1);
        return res;
    }
};