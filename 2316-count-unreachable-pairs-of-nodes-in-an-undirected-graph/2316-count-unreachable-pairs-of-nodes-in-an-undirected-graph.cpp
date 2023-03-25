typedef long long ll;
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        vector<int>dsu(n,-1);
        function<int(int)>DSU_FIND=[&](int x)->int
        {
            return dsu[x]<0?x:(dsu[x]=DSU_FIND(dsu[x]));
        };
        auto DSU_MERGE=[&](int u,int v)->void
        {
            u=DSU_FIND(u);
            v=DSU_FIND(v);
            
            if(u==v)
            {
                return;
            }
            if(dsu[u]<dsu[v])
            {
                swap(u,v);
            }
            dsu[v]+=dsu[u];
            dsu[u]=v;
        };
        for(auto& it:edges)
        {
            DSU_MERGE(it[0],it[1]);
        }
        ll ans=n*(n-1ll);
        for(int i=0;i<n;++i)
        {
            if(DSU_FIND(i)==i)
            {
                int ert=-dsu[i];
                ans-=ert*(ert-1ll);
            }
        }
        return ans>>1;
    }
};