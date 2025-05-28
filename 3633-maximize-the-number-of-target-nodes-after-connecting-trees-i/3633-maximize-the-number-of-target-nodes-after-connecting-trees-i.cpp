class Solution{
public:
    vector<int>maxTargetNodes(vector<vector<int>>&edges1,vector<vector<int>>&edges2,int k){
        int n=0,m=0;
        for(auto &it:edges1)
        {
            n=max(n,max(it[0],it[1])+1);
        }
        for(auto &it:edges2)
        {
            m=max(m,max(it[0],it[1])+1);
        }
        vector<vector<int>>adj1(n,vector<int>()),adj2(m,vector<int>());
        for(auto &it:edges1)
        {
            adj1[it[0]].push_back(it[1]);
            adj1[it[1]].push_back(it[0]);
        }
        for(auto &it:edges2)
        {
            adj2[it[0]].push_back(it[1]);
            adj2[it[1]].push_back(it[0]);
        }
        auto bfs=[&](int in,const vector<vector<int>>&adj,int vals,int dst)
        {
            vector<int>Track(vals,-1);
            queue<int>q;
            q.push(in);
            Track[in]=0;
            int res=1;
            while(!q.empty())
            {
                int u=q.front();q.pop();
                for(auto &it:adj[u])
                {
                    if(Track[it]==-1)
                    {
                        Track[it]=Track[u]+1;
                        if(Track[it]<=dst)res++;
                        if(Track[it]<dst)q.push(it);
                    }
                }
            }
            return res;
        };
        int ans=0;
        vector<int>Arr(n,0),Brr(m,0);
        for(int i=0;i<n;++i)
        {
            Arr[i]=bfs(i,adj1,n,k);
        }
        if(k>=1)
        {
            for(int j=0;j<m;++j)
            {
                Brr[j]=bfs(j,adj2,m,k-1);
            }
        }
        if(k>=1)
        {
            for(int j=0;j<m;++j)
            {
                ans=max(ans,Brr[j]);
            }
        }
        int tmp=ans;
        vector<int>Ans(n,0);
        for(int i=0;i<n;++i)
        {
            Ans[i]=(k==0)?1:(Arr[i]+tmp);
        }
        return Ans;
    }
};