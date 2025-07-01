class Solution {
public:
    int find(int node,vector<int>& par)
    {
        if(par[node]==node)return node;
        return par[node]=find(par[node],par);
    }
    void Union(int u,int v,vector<int>& par,vector<int>& size)
    {
        int x=find(u,par),y=find(v,par);
        if(x==y)return;
        if(size[x]<size[y])
        {
            par[x]=y;
            size[y]+=size[x];
        }
        else
        {
            par[y]=x;
            size[x]+=size[y];
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>par(n);
        iota(par.begin(),par.end(),0LL);
        vector<vector<int>>edges;
        for(int i=0;i<n;++i)
        {
            for(int j=i;j<n;++j)
            {
                if(isConnected[i][j]==1)edges.push_back({i,j});
            }
        }
        vector<int>size(n,0);
        for(auto& it:edges)Union(it[0],it[1],par,size);
        int ans=0;
        for(int i=0;i<n;++i)
        {
            //if node is its own parent -> it's a province
            if(i==par[i])ans++;
        }
        return ans;
    }
};