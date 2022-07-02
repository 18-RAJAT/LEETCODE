#define ll long long
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
#define f1(a,b) for(int i=0;i<n-2;++i)
#define fff(a,b,c) for(int j=i;j<n-2;j+=i+2)
// #define g __gcd(nums[0],nums[n-1])


class Solution {
public:
    int countPrimes(int n) {
       if(n<=2){return 0;}
        VI f(n-2,1);
        int ct=0;
        f1(0,n-2)
        if(f[i]){ct++;fff(a,b,c)f[j]=0;}
        return ct;
    }
};