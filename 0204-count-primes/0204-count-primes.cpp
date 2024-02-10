class Solution {
public:
    int countPrimes(int n) {
        if(n<=1)
        {
            return 0;
        }
        int prime[n];
        for(int i=0;i<n;++i)
        {
            prime[i]=1;
        }
        prime[0]=0;
        prime[1]=0;
        for(int i=2;i*i<=n;++i)
        {
            if(prime[i])
            {
                for(int j=i*i;j<n;j+=i)//for optimization we can start from i*i instead of 2*i because all the numbers before i*i are already marked as false by the previous numbers
                {
                    prime[j]=0;
                }
            }
        }
        int count=0;
        for(int i=2;i<n;++i)
        {
            if(prime[i])
            {
                count++;
            }
        }
        return count;
    }
};