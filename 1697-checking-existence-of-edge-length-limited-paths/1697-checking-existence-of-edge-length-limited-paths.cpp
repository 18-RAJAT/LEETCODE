class union_find
{
    private:
    vector<int>parent;
    vector<int>rank;
    public:
    union_find(int n)
    {
        parent=vector<int>(n,0);
        rank=vector<int>(n,1);
        iota(parent.begin(),parent.end(),0);
    }
    int find(int x)
    {
        if(x==parent[x])
        {
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    void merge(int x,int y)
    {
        if(rank[x]>rank[y])
        {
            parent[y]=x;
            rank[x]+=rank[y];
        }
        else
        {
             parent[x]=y;
             rank[y]+=rank[x];
        }
    }
    bool is_connected(int x,int y)
    {
        return find(x)==find(y);
    }
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>&nums, vector<vector<int>>& q) 
    {    
        union_find dsu(n);
        sort(nums.begin(),nums.end(),[&](auto &a,auto &b)
             {return a[2]<b[2];});
        for(int i=0;i<q.size();i++)
        {
            q[i].push_back(i);
        }
        sort(q.begin(),q.end(),[&](auto &a,auto &b)
             {return a[2]<b[2];});
        int i=0;
        int X=nums.size();
        vector<bool>ans(q.size());
        for(auto it:q)
        {
            while(i<X and nums[i][2]<it[2])
            {
                int p1=dsu.find(nums[i][0]);
                int p2=dsu.find(nums[i][1]);
                if(p1!=p2)
                {
                   dsu.merge(p1,p2);
                }
                i++;
            }
            ans[it[3]]=dsu.is_connected(it[0],it[1]);
        }
        return ans;
    }
};