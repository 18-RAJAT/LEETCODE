class Solution {
public:
    int minOperations(string s, int k) {
        int n=s.size();
        long long z=0;
        for(int i=0;i<=n;++i)z+=(s[i]=='0'?1:0);
        long long o=n-z;
        if(z==0)return 0;
        for(int i=1;i<=n;++i)
        {
            long long op=i*k;
            if(op<z || (op-z)&1)continue;
            long long p=i-(i&1),q=i-(i%2==0?1:0);
            long long x=z*q,y=o*p;
            if(op<=x+y)return i;
        }
        return -1;
    }
};