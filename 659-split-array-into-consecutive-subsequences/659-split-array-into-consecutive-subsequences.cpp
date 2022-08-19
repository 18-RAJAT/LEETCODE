#define MP make_pair
#define PB push_back
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
typedef vector<PII> VIII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef priority_queue<pair<int,pair<int,int>>> PQVI;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
#define ff(a,b) for(int i=a;i<b;i++)
#define f1(i,s,e) for(long long int i=s;i<e;i++)
#define ff1(pass) for(long long int i=n-2;i>=0;--i)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define FOREACH(n) for(auto it:n)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back


class Solution {
public:
    bool isPossible(vector<int>& nums) {
        MPII m,end;
        for(int it:nums)
        {
            m[it]++;
        }
        
        int subseq=0;
        for(int it:nums)
        {
            if(m[it]==0)continue;
            m[it]--;
            if(end[it-1]>0)
            {
                end[it-1]--;
                end[it]++;
            }
            else if(m[it+1] and m[it+2])
            {
                m[it+1]--;
                m[it+2]--;
                end[it+2]++;
            }
            else{return false;}
        }
        return true;
    }
};