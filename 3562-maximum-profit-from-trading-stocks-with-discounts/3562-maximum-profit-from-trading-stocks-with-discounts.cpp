class Solution {
public:
    void dfs(int u,const vector<int>& ar,const vector<int>& br,const vector<vector<int>>& tree,vector<vector<vector<int>>>& dp,int x)
    {
        vector<pair<vector<int>,vector<int>>>vp;
        for(auto& it:tree[u])
        {
            dfs(it,ar,br,tree,dp,x);
            vp.emplace_back(dp[it][0],dp[it][1]);
        }
        for(int i=0;i<=1;++i)
        {
            int price=i?ar[u]/2:ar[u],profit=br[u]-price;
            vector<int>ok1(x+1,0),ok2(x+1,0);
            for(auto& it:vp)
            {
                vector<int>temp(x+1,0);
                for(int j=0;j<=x;++j)
                {
                    if(ok2[j]==0 && j!=0)continue;
                    for(int k=0;j+k<=x;++k)
                    {
                        temp[j+k]=max(temp[j+k],ok2[j]+it.first[k]);
                    }
                }
                ok2=move(temp);
            }
            for(int j=0;j<=x;++j)ok1[j]=max(ok1[j],ok2[j]);
            if(price<=x)
            {
                vector<int>tmp(x+1,0);
                for(auto& it1:vp)
                {
                    vector<int>temp(x+1,0);
                    for(int j=0;j<=x;++j)
                    {
                        if(tmp[j]==0 && j!=0)continue;
                        for(int k=0;j+k<=x;++k)
                        {
                            temp[j+k]=max(temp[j+k],tmp[j]+it1.second[k]);
                        }
                    }
                    tmp=move(temp);
                }
                for(int p=price;p<=x;++p)
                {
                    ok1[p]=max(ok1[p],tmp[p-price]+profit);
                }
            }
            dp[u][i]=move(ok1);
        }
    }
    int maxProfit(int n,vector<int>& ar,vector<int>& br,vector<vector<int>>& hierarchy,int x)
    {
        vector<vector<int>>tree(n);
        for(auto& it:hierarchy)
        {
            tree[it[0]-1].push_back(it[1]-1);
        }
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(x+1,0)));
        dfs(0,ar,br,tree,dp,x);
        int ans=0;
        for(int i=0;i<=x;++i)ans=max(ans,dp[0][0][i]);
        return ans;
    }
};