class DisjointSet
{
    public:
    vector<int>parent;
    vector<int>rank;
    DisjointSet(int n)
    {
        parent.resize(n+1);
        rank.resize(n+1);
        parent[0]=0,rank[0]=0;
        for(int i=1;i<=n;++i)
        { 
            parent[i]=i;
            rank[i]=0;
        }
    }
    int Find(int n)
    {
        if(parent[n]==n)
        {
            return n;
        }
        return parent[n]=Find(parent[n]);
    }
    void Union(int u,int v)
    {
        int a=Find(u),b=Find(v);
        if(rank[a]<rank[b])
        {
            parent[a]=b;
        }
        else if(rank[b]<rank[a])
        {
            parent[b]=a;
        }
        else
        {
            parent[a]=b;
            rank[b]++;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DisjointSet Ds(n);
        for(int i=0;i<n;++i)
        {
            int u=Ds.Find(edges[i][0]);
            int v=Ds.Find(edges[i][1]);
            if(u!=v)
            {
                Ds.Union(u,v);
            }
            else
            {
                return{edges[i][0],edges[i][1]};
            }
        }
        return {};
    }
};