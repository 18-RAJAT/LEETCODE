class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        queue<pair<int,int>>q;
        int n=graph.size();
        vector<vector<bool>>seen(n,vector<bool>(1<<n));
        for(int i=0;i<n;++i)
        {
            q.emplace(i,1<<i);
            seen[i][1<<i]=true;
        }
        for(int i=0;q.size();++i)
        {
            for(int j=q.size();j;--j)
            {
                auto [u,mask]=q.front();
                q.pop();
                if(mask==(1<<n)-1)
                {
                    return i;
                }
                for(auto& v:graph[u])
                {
                    if(!seen[v][mask|1<<v])
                    {
                        q.emplace(v,mask|1<<v);
                        seen[v][mask|1<<v]=true;
                    }
                }
            }
        }
        return -1;
    }
};