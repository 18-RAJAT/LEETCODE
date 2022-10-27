#define MP make_pair
#define INF (int)1e9
#define EPS 1e-9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define ll long long
#define all(x) sort(x.begin(), x.end())
#define ff(a,b) for(int i=a;i<b;i++)
#define f1(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define FOREACH(n) for(auto it:n)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<vector<int>> VII;
typedef vector<string> VS;
typedef vector<vector<string>> VVS;
typedef vector<PII> VIII;
typedef vector<VI> VVI;
typedef vector<pair<int,int>> vpii;
typedef map<int,int> MPII;
typedef map<string,int> msi;
typedef priority_queue<pair<int,pair<int,int>>> PQVI;
typedef unordered_map<string,vector<string>> MPSVS;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;


class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        vpii a,b;
        f1(i,0,n)
        {
            f1(j,0,n)
            {
                if(img1[i][j]==1)
                {
                    a.pb(make_pair(i,j));
                }
            }
        }
        f1(i,0,n)
        {
            f1(j,0,n)
            {
                if(img2[i][j]==1)
                {
                    b.pb(make_pair(i,j));
                }
            }
        }
        msi ct;
        for(auto x:a)
        {
            for(auto y:b)
            {
                ct[to_string(x.first-y.first)+" "+to_string(x.second-y.second)]++;
            }
        }
        int ans=0;
        for(auto it:ct)
        {
            ans=max(ans,it.second);
        }
        return ans;      
    }
};