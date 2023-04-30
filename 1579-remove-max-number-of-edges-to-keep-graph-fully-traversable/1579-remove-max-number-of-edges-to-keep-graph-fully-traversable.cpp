class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int ans=0;
        vector<int>parent(n+1);
        for(int i=1;i<=n;++i)
        {
            parent[i]=i;
        }
        function<int(vector<int>&,int)> find=[&](vector<int>& parent,int x)->auto
        {
            if(parent[x]==x)
            {
                return x;
            }
            return parent[x]=find(parent,parent[x]);
        };
        for(auto edge:edges)
        {
            if(edge[0]==3)
            {
                int x=find(parent,edge[1]);
                int y=find(parent,edge[2]);
                if(x!=y)
                {
                    parent[x]=y;
                }
                else
                {
                    ++ans;
                }
            }
        }
        vector<int> parent1=parent;
        for(auto edge:edges)
        {
            if(edge[0]==1)
            {
                int x=find(parent,edge[1]);
                int y=find(parent,edge[2]);
                if(x!=y)
                {
                    parent[x]=y;
                }
                else
                {
                    ++ans;
                }
            }
        }
        for(auto edge:edges)
        {
            if(edge[0]==2)
            {
                int x=find(parent1,edge[1]);
                int y=find(parent1,edge[2]);
                if(x!=y)
                {
                    parent1[x]=y;
                }
                else
                {
                    ++ans;
                }
            }
        }
        for(int i=1;i<=n;++i)
        {
            if(find(parent,i)!=find(parent,1))
            {
                return -1;
            }
        }
        for(int i=1;i<=n;++i)
        {
            if(find(parent1,i)!=find(parent1,1))
            {
                return -1;
            }
        }
        return ans;
    }
};