class Solution {
public:
    vector<int>color,visit,chk;
    vector<vector<int>>adj,dist;
    bool bfs(int i)
    {
        queue<int>q;
        q.push(i);
        visit[i]=0;
        while(!q.empty())
        {
            int f=q.front();
            chk.push_back(f);
            q.pop();
            for(auto& it:adj[f])
            {
                if(~visit[it])
                {
                    if(visit[it]!=(!visit[f]))return 0;
                }
                else
                {
                    visit[it]=(!visit[f]);
                    q.push(it);
                }
            }
        }
        return 1;   
    }
    void bfs1(int i)
    {
        dist[i][i]=1;
        queue<int>q;
        q.push(i);
        while(!q.empty())
        {
            int f=q.front();
            q.pop();
            for(auto it :adj[f])
            {
                if(dist[i][it]>dist[i][f]+1)
                {
                    dist[i][it]=dist[i][f]+1;
                    q.push(it);
                }
            }
        }    
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        adj=vector<vector<int>>(n+1);
        dist=vector<vector<int>>(n+1,vector<int>(n+1,1e9));
        for(auto& it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        } 
        visit=vector<int>(n+1,-1);
        bool check=1;
        for(int i=1;i<=n;++i)
        {
            bfs1(i);
        }
        int ans=0;
        for(int i=1;i<=n;++i)
        {
            if(~visit[i])continue;
            check&=bfs(i);
            int x=0;
            for(int j=0;j<chk.size();++j)
            {
                for(int k=j;k<chk.size();++k)
                {
                    if(dist[chk[j]][chk[k]]<INT_MAX)
                    {
                        x=max(x,dist[chk[j]][chk[k]]);
                    }
                }
            }
            chk.clear();
            ans+=x;
        }
        if(check==0)return -1;
        for(int i=1;i<=n;++i)
        {
            for(auto& it:adj[i])
            {
                if(visit[it]!=(!visit[i]))return -1;
            }
         }
        return ans;      
    }
};