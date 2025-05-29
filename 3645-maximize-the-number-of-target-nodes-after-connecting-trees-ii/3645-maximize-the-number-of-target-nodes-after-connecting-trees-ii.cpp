class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size()+1;
        vector<vector<int>>adj1(n,vector<int>());
        for(auto &it:edges1)
        {
            int u=it[0],v=it[1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        int m=edges2.size()+1;
        vector<vector<int>>adj2(m,vector<int>());
        for(auto &it:edges2)
        {
            int u=it[0],v=it[1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }
        auto bfs=[&](int in,const vector<vector<int>>&adj,vector<int>&color,int&A,int&B)
        {
            int n_nodes=adj.size();
            color.assign(n_nodes,-1);
            queue<int>q;
            q.push(in);
            color[in]=0;
            A=1,B=0;
            while(!q.empty())
            {
                int u=q.front();q.pop();
                for(auto &v:adj[u])
                {
                    if(color[v]==-1)
                    {
                        color[v]=color[u]^1;
                        if(color[v]==0)A++;
                        else B++;
                        q.push(v);
                    }
                }
            }
        };
        vector<int>c1,c2;
        int x,y,F1,F2;
        bfs(0,adj1,c1,x,y);
        bfs(0,adj2,c2,F1,F2);
        int res=max(F1,F2);
        vector<int>Ans(n,0);
        for(int i=0;i<n;++i)
        {
            if(c1[i]==0)Ans[i]=x+res;
            else Ans[i]=y+res;
        }
        return Ans; 
    }
};