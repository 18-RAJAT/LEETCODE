#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;

ll mod_pow(ll x,ll y)
{
    ll res=1;
    x%=MOD;
    while(y>=1)
    {
        if(y&1)res=res*x%MOD;
        x=x*x%MOD;
        y>>=1;
    }
    return res;
}
class Solution{
public:
    int countBalancedPermutations(string num){
        int n=num.size();
        int dig[10]={0};
        for(int i=0;i<n;++i)
        {
            dig[num[i]-'0']++;
        }
        ll tot=0;
        for(int d=0;d<10;++d)
        {
            tot+=(ll)d*dig[d];
        }
        if(tot%2!=0)
        {
            return 0;
        }
        ll tar=tot/2;
        int k=(n+1)/2;
        vector<vector<vector<ll>>>dp(11,vector<vector<ll>>(k+1,vector<ll>(tar+1,0)));
        dp[0][0][0]=1;
        for(int d=0;d<10;++d)
        {
            for(int c=0;c<=k;++c)
            {
                for(int s=0;s<=tar;++s)
                {
                    if(dp[d][c][s]==0)continue;
                    for(int t=0;t<=dig[d] && t+c<=k && t*d<=tar-s;++t)
                    {
                        ll res=1;
                        for(int i=1;i<=t;++i)
                        {
                            res=res*(dig[d]-i+1)%MOD;
                            ll inv=mod_pow(i,MOD-2);
                            res=res*inv%MOD;
                        }
                        int nxt=d+1,nxtc=c+t,nxts=s+t*d;
                        dp[nxt][nxtc][nxts]=(dp[nxt][nxtc][nxts]+dp[d][c][s]*res)%MOD;
                    }
                }
            }
        }
        if(k<0 || k>n || tar<0)return 0;
        ll ret=dp[10][k][tar];
        if(ret==0)return 0;
        vector<long long>ndp(n+1,1);
        for(int i=1;i<=n;++i)
        {
            ndp[i]=ndp[i-1]*i%MOD;
        }
        ll prod=1;
        for(int d=0;d<10;++d)
        {
            for(int i=1;i<=dig[d];++i)
            {
                prod=prod*i%MOD;
            }
        }
        ll pre1=ndp[k],pre2=ndp[n-k];
        ll prod_inv=mod_pow(prod,MOD-2);
        ll ans=ret*pre1%MOD;
        // for(int i=0;i<ans;++i)
        // {
        //     cout<<ndp[i]<<" ";
        // }
        // cout<<endl;
        ans=ans*pre2%MOD;
        ans=ans*prod_inv%MOD;
        return(long long)ans;
    }
};