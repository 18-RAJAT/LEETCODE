class Solution {
public:
    char processStr(string s, long long k) {
        int n=s.size();
        vector<long long>ar(n);
        long long res=0;
        for(int i=0;i<n;++i)
        {
            if(s[i]>='a' && s[i]<='z')res+=1LL;
            else if(s[i]=='*' && res>=1)res-=1LL;
            else if(s[i]=='#')res*=2LL;
            ar[i]=res;
        }
        if(res<=k)return '.';
        long long id=k;
        for(int i=n-1;~i;--i)
        {
            if(s[i]=='#')
            {
                long long cur=ar[i]/2;
                if(cur<=id)
                {
                    long long rem=id-cur;
                    id=rem;
                }
            }
            else if(s[i]=='%')
            {
                id=ar[i]-id-1;
            }
            else if(s[i]!='*')
            {
                if(ar[i]==id+1)return s[i];
            }
        }
        return '.';
    }
};