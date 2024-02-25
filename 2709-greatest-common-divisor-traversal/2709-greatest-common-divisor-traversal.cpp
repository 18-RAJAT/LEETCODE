class Solution {
public:
    int find(vector<int>&parent,int x)
    {
        if(parent[x]==x)
        {
            return x;
        }
        return parent[x]=find(parent,parent[x]);
    }
    void union_check(int a,int b,vector<int>&size,vector<int>&parent)
    {
        int x=find(parent,a);
        int y=find(parent,b);
        if(x!=y)
        {
            if(size[x]<size[y])
            {
                swap(x,y);
            }
            size[x]+=size[y];
            parent[y]=x;
        }
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        int n=2e5+5;
        if(nums.size()==1)
        {
            return true;
        }
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]==1)
            {
                return false;
            }
        }
        vector<int>parent(n),size(n);
        for(int i=0;i<n;++i)
        {
            size[i]=1;
            parent[i]=i;
        }
        sort(nums.begin(),nums.end(),[&](int &a,int &b){return a>b;});
        for(auto &i: nums)
        {
            int x=i;
            for(int j=2;j<=sqrt(i);++j)
            {
                if(x%j==0)
                {
                    union_check(i,j,size,parent);
                    while(x%j==0)
                    {
                        x/=j;
                    }
                    union_check(i,j,size,parent);
                }
            }
            if(x>=2)
            {
                union_check(i,x,size,parent);
            }
        }
        unordered_set<int>s;
        for(int i=0;i<nums.size();++i)
        {
            s.insert(find(parent,nums[i]));
        }
        return s.size()==1?true:false;
    }
};