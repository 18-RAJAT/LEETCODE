#define ll long long
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
#define f(a,b) for(int i=a;i<b;i++)
 
// template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);} 
// template<typename T> T lcm(T a, T b){return(a*(b/gcd(a,b)));} 

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& dk) {
        int n=dk.size();
        MPII m;
        f(0,n){m[dk[i]]++;}
        int gcd=0;
        for(auto it:m){gcd=__gcd(gcd,it.second);}
        return gcd>1;
    }
};