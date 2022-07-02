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
#define g __gcd(nums[0],nums[n-1])
class Solution {
public:
    string gcdOfStrings(string s1, string s2) {
        string s;
        int n=s1.length();int m=s2.length();
        int temp=__gcd(n,m);
        if(s1+s2==s2+s1)
        s=s1.substr(0,temp);
        return s;
    }
};