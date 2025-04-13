class Solution{
public:
    const int mod=1e9+7;
    long long power(long long a,long long b,long long p=1)
    {
        if(a==0)return 0;
        long long res=1;
        a%=p;
        while(b>=1)
        {
            if(b&1)res=(res*a)%p;
            b>>=1;
            a=(a*a)%p;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        int even=power(5,(n+1)/2,mod),odd=power(4,n/2,mod);
        return (1LL*even*odd)%mod;
    }
};