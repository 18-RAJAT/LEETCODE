#define ll long long int 
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define ff(a,b) for(int i=a;i<b;i++)
#define f1(i,s,e) for(long long int i=s;i<e;i++)
#define ff1(pass) for(long long int i=n-2;i>=0;--i)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)


class Solution {
public:
    int concatenatedBinary(int n) {
        ll answer=0;
        // if(n==1){return n;}
        // return (n*n)%MOD;
        ll current=0;
        cf(i,1,n)
        {
            if((i&(i-1))==0)current++;
            answer=(answer<<current)%MOD;
            answer+=i%MOD;
        }
        return answer;
    }
};