class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        vector<int>parent(n);
        iota(parent.begin(),parent.end(),0);
        function<int(int)>find=[&](int x)->int
        {
            return parent[x]==x?x:parent[x]=find(parent[x]);
        };
        auto unite=[&](int x,int y)
        {
            x=find(x);
            y=find(y);
            if(x!=y)
            {
                parent[x]=y;
            }
        };
        auto isSimilar=[&](string& a,string& b)->bool
        {
            int count=0;
            for(int i=0;i<a.size();++i)
            {
                if(a[i]!=b[i])
                {
                    count++;
                }
                if(count>2)
                {
                    return false;
                }
            }
            return true;
        };
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                if(isSimilar(strs[i],strs[j]))
                {
                    unite(i,j);
                }
            }
        }
        int count=0;
        for(int i=0;i<n;++i)
        {
            if(parent[i]==i)
            {
                count++;
            }
        }
        return count;
    }
};