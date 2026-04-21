class Solution{
public:
    vector<int>par;
    int find(int x)
    {
        if(par[x]!=x)par[x]=find(par[x]);
        return par[x];
    }
    void unite(int a,int b)
    {
        par[find(a)]=find(b);
    }
    int minimumHammingDistance(vector<int>&source,vector<int>&target,vector<vector<int>>&allowedSwaps){
        int n=source.size();
        par.resize(n);
        iota(par.begin(),par.end(),0);
        for(auto& it:allowedSwaps)unite(it[0],it[1]);
        unordered_map<int,unordered_map<int,int>>mp;
        for(int i=0;i<n;++i)mp[find(i)][source[i]]++;
        int ans=0;
        for(int i=0;i<n;++i)
        {
            int x=find(i);
            auto& it=mp[x];
            if(it.count(target[i]) && it[target[i]]>=1)it[target[i]]--;
            else ans++;
        }
        return ans;
    }
};