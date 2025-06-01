class Solution {
public:
    long long int distributeCandies(long long int n, long long int limit) {
        if(3*limit<n)
        {
            return 0;
        }
        function<long long int(long long int)>get=[&](long long int x)->long long int
        {
            return 1LL*x*(x-1)/2;
        };
        long long int ans=get(n+2);
        if(n>limit)
        {
            ans-=3*get(n-limit+1);
        }
        if(n-2>=2*limit)
        {
            ans+=3*get(n-2*limit);
        }
        return (long long int)ans;
    }
};