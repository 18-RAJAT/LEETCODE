class Solution {
public:
    vector<int>par;
    int find(int v)
    {
        if(v==par[v])return v;
        return par[v]=find(par[v]);
    }
    int Union(int a,int b)
    {
        a=find(a),b=find(b);
        if(a==b)return 1;
        par[b]=a;
        return 0;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        for(int i=0;i<=n;++i)par.push_back(i);
        for(auto& it:edges)
        {
            if(Union(it[0],it[1]))return {it[0],it[1]};
        }
        return {-1,-1};
    }
};