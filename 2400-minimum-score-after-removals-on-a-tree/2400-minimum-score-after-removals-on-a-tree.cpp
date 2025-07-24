class Solution {
public:
    vector<int>in,out,x;
    int t;
    void dfs(int u,int p,vector<vector<int>>& g,vector<int>& a)
    {
        in[u]=t,t++;
        x[u]=a[u];
        for(auto& it:g[u])
        {
            if(it!=p)
            {
                dfs(it,u,g,a);
                x[u]^=x[it];
            }
        }
        out[u]=t,t++;
    }
    bool anc(int u,int v)
    {
        return in[u]<=in[v] && out[u]>=out[v];
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n=nums.size();
        x.resize(n);
        in.resize(n);
        out.resize(n);
        t=0;
        vector<vector<int>>g(n);
        for(auto& it:edges){
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        dfs(0,-1,g,nums);
        int tmp=x[0],res=INT_MAX;
        for(int i=1;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                int p,q,r;
                if(anc(i,j))
                {
                    r=x[j];
                    q=x[i]^x[j];
                    p=tmp^x[i];
                }
                else if(anc(j,i))
                {
                    r=x[i];
                    q=x[j]^x[i];
                    p=tmp^x[j];
                }
                else
                {
                    q=x[i];
                    r=x[j];
                    p=tmp^x[i]^x[j];
                }
                res=min(res,max({p,q,r})-min({p,q,r}));
            }
        }
        return res;
    }
};