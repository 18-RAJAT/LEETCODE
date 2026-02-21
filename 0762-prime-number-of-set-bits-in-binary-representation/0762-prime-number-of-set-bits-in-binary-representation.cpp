class Solution {
public:
    int prime(int n)
    {
        if(n<=1)return false;
        for(int i=2;i*i<=n;++i)
        {
            if(n%i==0)return 0;
        }
        return 1;
    }
    int countPrimeSetBits(int left, int right) {
        int ans=0;
        for(int i=left;i<=right;++i)
        {
            int bt=__builtin_popcount(i);
            if(prime(bt))ans++;
        }
        return ans;
    }
};