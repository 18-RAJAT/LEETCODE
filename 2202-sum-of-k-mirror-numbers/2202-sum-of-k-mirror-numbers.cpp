class Solution {
public:
    long long check(long long n,int m)
    {
        long long x=n;
        if(m)x/=10;
        while(x>=1)
        {
            n=n*10+x%10;
            x/=10;
        }
        return n;
    }
    int pali(long long n,int m)
    {
        vector<int>dig;
        while(n>=1)
        {
            dig.push_back(n%m);
            n/=m;
        }
        int i=0,j=dig.size()-1;
        while(i<j)
        {
            if(dig[i++]!=dig[j--])return 0;
        }
        return 1;
    }
    long long kMirror(int k,int n)
    {
        long long ans=0;
        for(long long i=1;n>=1;i*=10)
        {
            for(long long j=i;n>=1 && j<i*10;++j)
            {
                long long tmp=check(j,1);
                if(pali(tmp,k))
                {
                    ans+=tmp;
                    n--;
                }
            }
            for(long long j=i;n>=1 && j<i*10;++j)
            {
                long long tmp=check(j,0);
                if(pali(tmp,k))
                {
                    ans+=tmp;
                    n--;
                }
            }
        }
        return ans;
    }
};