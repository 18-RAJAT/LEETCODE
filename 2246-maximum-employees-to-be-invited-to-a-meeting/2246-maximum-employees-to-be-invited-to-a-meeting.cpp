class Solution {
public:
    int TopoSort(int i,vector<int>& ind,vector<int> g[],vector<int>& v)
    {
        queue<int>q;
        q.push(i);
        int temp=i;
        while(q.size()>=1)
        {
            int n=q.front();
            temp=n,v[n]=1;
            q.pop();
            for(auto& it:g[n])
            {
                ind[it]--;
                if(ind[it]==0)q.push(it);
            }
        }
        return g[temp][0];
    }
    //1
    int dfs(int n,vector<int> g[],vector<int>& v)
    {
        int cnt=0;
        v[n]=1;
        for(auto& it:g[n])if(!v[it])cnt+=dfs(it,g,v);
        return 1+cnt;
    }
    //2
    int Dfs(int n,vector<int> g[],int a,vector<int>& v)
    {
        v[n]=1;
        int cnt=0;
        for(auto& it:g[n])if(it!=a)cnt=max(cnt,Dfs(it,g,a,v));
        return 1+cnt;
    }
    int maximumInvitations(vector<int>& fav)
    {
        int n=fav.size(),ans1=0,res=0;
        vector<int>g[n],v(n,0),ind(n,0),ar[n];
        for(int i=0;i<n;++i)
        {
            g[i].push_back(fav[i]);
            ar[fav[i]].push_back(i);
            ind[fav[i]]++;
        }
        for(int i=0;i<n;++i)
        {
            if(ind[i]==0 && !v[i] && ~ind[i])
            {
                int p=TopoSort(i,ind,g,v);
                if(g[g[p][0]][0]==p)
                {
                    int a=g[p][0],again=Dfs(p,ar,a,v)-1;
                    v[p]=0;
                    ans1+=again;
                }
            }
        }
        int count=0;
        for(int i=0;i<n;++i)
        {
            if(!v[i])
            {
                int call=dfs(i,g,v);
                (call==2)?count++:res=max(res,call);
            }
        }
        return max(res,ans1+2*count);
    }
};