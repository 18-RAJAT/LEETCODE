class Solution {
public:
    int countPrimes(int n) {
        // function<bool(int)>isPrime=[&](int n)->bool
        // {
        //     for(int i=2;i*i<=n;++i)
        //     {
        //         if(n%i==0)
        //         {
        //             return false;
        //         }
        //     }
        //     return true;
        // };
        // int cntPrimes=0;
        // for(int i=2;i<n;++i)
        // {
        //     if(isPrime(i))
        //     {
        //         cntPrimes++;
        //     }
        // }
        // return cntPrimes;
        
        //using Sieve of Eratosthenes O(n log log n)
        bool prime[n+1];
        memset(prime,true,sizeof(prime));
        
        for(int i=2;i*i<n;++i)
        {
            if(prime[i])
            {
                for(int j=i*i;j<n;j+=i)
                {
                    prime[j]=false;
                }
            }
        }
        int cnt=0;
        for(int i=2;i<n;++i)
        {
            if(prime[i])
            {
                cnt++;
            }
        }
        return cnt;
    }
};