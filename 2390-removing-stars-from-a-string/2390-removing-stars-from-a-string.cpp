#define MP make_pair
#define INF (int)1e9
#define EPS 1e-9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()
const double pi=acos(-1.0);
#define ll long long
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<vector<int>> VII;
typedef vector<string> VS;
typedef vector<vector<string>> VVS;
typedef vector<PII> VIII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef priority_queue<pair<int,pair<int,int>>> PQVI;
typedef unordered_map<string,vector<string>> MPSVS;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
#define all(x) sort(x.begin(), x.end())
#define ff(a,b) for(int i=a;i<b;i++)
#define f1(i,s,e) for(long long int i=s;i<e;i++)
#define rf(val) for(int i=s.length()-1;i>=0;i--)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define FOREACH(n) for(auto it:n)
#define pb push_back
#define PB pop_back
#define eb emplace_back


class Solution {
public:
    string removeStars(string s) {
        int ct=0;
        string str="";
        
        // for(auto it:s)
        // {
        //     if(str.length()>0 and it=='*')str.PB();
        //     else str=str+it;
        // }
        // return str;
        
        rf(val)
        {
            if(s[i]=='*')ct++;
            else if(s[i]!='*' and ct==0){str+=s[i];}
            else{if(ct>0)ct--;}
        }
        reverse(str.begin(),str.end());
        return str;
    }
};