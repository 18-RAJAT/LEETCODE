class Solution {
public:
    int mod=1e9+7;
    bool recur(int n,int m)
    {
        int x=-1;
        for(int i=0;i<m;++i)
        {
            int y=n%3;
            n/=3;
            if(x==y)return false;
            x=y;
        }
        return true;
    }
    bool check(int a,int b,int m)
    {
        for(int i=0;i<m;++i)
        {
            if(a%3==b%3)return false;
            a/=3;b/=3;
        }
        return true;
    }
    int colorTheGrid(int m, int n) {
        int chk=pow(3,m);
        vector<int>ar;
        for(int i=0;i<chk;++i)
        {
            if(recur(i,m))
            {
                ar.push_back(i);
            }
        }
        map<int,vector<int>>adj;
        for(auto& it:ar)
        {
            for(auto& itr:ar)
            {
                if(check(it,itr,m))
                {
                    adj[it].push_back(itr);
                }
            }
        }
        map<int,int>dp;
        for(auto& it:ar)dp[it]=1;
        for(int i=1;i<n;++i)
        {
            map<int,int>ndp;
            for(auto& [x,y]:dp)
            {
                for(auto& it:adj[x])
                {
                    ndp[it]=(ndp[it]+y)%mod; 
                }
            }
            dp=ndp;
        }
        int ans=0;
        for(auto& [x,y]:dp)ans=(ans+y)%mod;
        return ans; 

    }
};