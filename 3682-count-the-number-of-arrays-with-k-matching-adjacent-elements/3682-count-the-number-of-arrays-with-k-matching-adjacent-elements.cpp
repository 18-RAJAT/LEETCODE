typedef long long ll;
class Solution
{
public:
    //Rajat joshi template
    const int Mod=1000000007;
    ll ModPower(ll b,ll e)
    {
        ll res=1;
        b%=Mod;
        while(e>0)
        {
            if(e&1)res=(res*b)%Mod;
            b=(b*b)%Mod;
            e>>=1;
        }
        return res;
    }
    void Compute(int size,vector<ll>& Fact,vector<ll>& Inv)
    {
        Fact[0]=1;
        for(int i=1;i<size;++i)Fact[i]=(Fact[i-1]*i)%Mod;
        Inv[size-1]=ModPower(Fact[size-1],Mod-2);
        for(int i=size-2;~i;--i)Inv[i]=(Inv[i+1]*(i+1))%Mod;
    }
    ll Combination(int n,int k,vector<ll>& Fact,vector<ll>& Inv)
    {
        if(k<0 || n<k)return 0;
        return (((Fact[n]*Inv[k])%Mod)*Inv[n-k])%Mod;
    }
    int countGoodArrays(int n,int m,int k){
        if(n-1<k)return 0;
        vector<ll>Fact(n,1),Inv(n,1);
        Compute(n,Fact,Inv);
        ll tot=Combination(n-1,k,Fact,Inv),md=ModPower(m-1,n-1-k);
        return (int)(((tot*m)%Mod*md)%Mod);
    }
};