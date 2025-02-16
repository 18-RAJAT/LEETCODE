class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int>res(2*n-1,0);
        vector<bool>vis(n+1,false);
        function<bool(int)>dfs=[&](int i)
        {
            if(i==res.size())return true;
            if(res[i])return dfs(i+1);
            for(int x=n;~x;--x)
            {
                if(vis[x])continue;
                if(x==1)
                {
                    res[i]=1;
                    vis[1]=true;
                    if(dfs(i+1))return true;
                    res[i]=0;
                    vis[1]=false;
                }
                else
                {
                    if(i+x<res.size() && res[i+x]==0)
                    {
                        res[i]=res[i+x]=x;
                        vis[x]=true;
                        if(dfs(i+1))return true;
                        res[i]=res[i+x]=0;
                        vis[x]=false;
                    }
                }
            }
            return false;
        };
        dfs(0);
        return res;
    }
};