class Solution 
{
    const int MOD=1e9+7;
    vector<int> fact,invFact;

public:
    int idealArrays(int n,int maxValue) 
    {
        precomputeFactorials(n+505);
        vector<int> arr=PrimeFact(maxValue);
        long long ans=0;
        for(int i=1;i<=maxValue;++i) 
        {
            unordered_map<int,int>factors=Fact(i,arr);
            long long count=1;
            for(auto& [i,it]:factors) 
            {
                count=count*Comb(n+it-1,it)%MOD;
            }
            ans=(ans+count)%MOD;
        }
        return ans;
    }

private:
    void precomputeFactorials(int size) 
    {
        fact.resize(size);
        invFact.resize(size);
        fact[0]=1;

        for(int i=1;i<size;++i) 
        {
            fact[i]=(long long)fact[i-1]*i%MOD;
        }

        invFact[size-1]=modInverse(fact[size-1]);

        for(int i=size-2;~i;--i) 
        {
            invFact[i]=(long long)invFact[i+1]*(i+1)%MOD;
        }
    }

    vector<int> PrimeFact(int limit) 
    {
        vector<int> spf(limit+1);
        for(int i=2;i<=limit;++i) 
        {
            if(spf[i]==0) 
            {
                for(int j=i;j<=limit;j+=i) 
                {
                    if(spf[j]==0)
                    {
                        spf[j]=i;
                    }
                }
            }
        }
        return spf;
    }

    unordered_map<int,int>Fact(int num,const vector<int>& spf) 
    {
        unordered_map<int,int>mp;
        while(num>1) 
        {
            int prime=spf[num];
            mp[prime]++;
            num/=prime;
        }
        return mp;
    }

    long long Comb(int a,int b) 
    {
        if(b>a) return 0;
        return (long long)fact[a]*invFact[b]%MOD*invFact[a-b]%MOD;
    }

    int modInverse(int x) 
    {
        return (int)power(x,MOD-2);
    }

    long long power(long long base,long long exp) 
    {
        long long res=1;
        while(exp>0) 
        {
            if(exp&1)
            {
                res=res*base%MOD;
            }
            base=base*base%MOD;
            exp>>=1;
        }
        return res;
    }
};