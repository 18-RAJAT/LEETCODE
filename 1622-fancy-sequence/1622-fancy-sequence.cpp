class Fancy {
    long long MOD=1000000007,mul=1,add=0;
    vector<long>a;
    long modpow(long a,long b)
    {
        long r=1;
        while(b)
        {
            if(b&1)r=r*a%MOD;
            a=a*a%MOD;
            b>>=1;
        }
        return r;
    }

public:
    Fancy(){a.reserve(100000);}

    void append(int val)
    {
        long inv=modpow(mul,MOD-2);
        a.push_back((val-add+MOD)%MOD*inv%MOD);
    }

    void addAll(int inc)
    {
        add=(add+inc)%MOD;
    }

    void multAll(int m)
    {
        mul=mul*m%MOD;
        add=add*m%MOD;
    }

    int getIndex(int idx)
    {
        if(idx>=a.size())return -1;
        return(a[idx]*mul+add)%MOD;
    }
};