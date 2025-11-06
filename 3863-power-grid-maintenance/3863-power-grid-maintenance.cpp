class DSU
{
    vector<int>rank,parent;
    public:
    DSU(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);
       
        for(int i=0;i<n;++i)parent[i]=i;
    }
    int Find(int node)
    {
        if(parent[node]==node)return node;
        return parent[node]=Find(parent[node]);
    }
    void Union(int x,int y)
    {
        int p1=Find(x),p2=Find(y);
        if(p1==p2) return;
        if(rank[p1]>rank[p2])parent[p2]=p1;
        else if(rank[p1]<rank[p2])parent[p1]=p2;
        else
        {
            parent[p1]=p2;
            rank[p2]++;
        }
    }
};
class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU dsu(c);
        for(auto& it:connections)
        {
           dsu.Union(it[0],it[1]);
        }
        unordered_map<int,set<int>>mp;
        for(int i=1;i<=c;++i)
        {
            int p=dsu.Find(i);
            mp[p].insert(i);
        }
        vector<int>ans,ok(c+1,1);
        for(auto& it:queries)
        {
            int q=it[0],node=it[1];
            int p=dsu.Find(node);
            if(q==1)
            {
                if(ok[node]) ans.push_back(node);
                else if(mp[p].size()!=0)
                {
                   int chk=*(mp[p].begin());
                   ans.push_back(chk);
                }
                else ans.push_back(-1);
            }
            else
            {
                ok[node]=0;
                mp[p].erase(node);
            }
            
        }
        return ans;
    }
};