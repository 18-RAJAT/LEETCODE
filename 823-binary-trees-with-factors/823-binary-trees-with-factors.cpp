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
typedef vector<vector<string>> VVS;
typedef vector<PII> VIII;
typedef vector<VI> VVI;
typedef map<int,ll> MPII;
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
#define ff1(pass) for(long long int i=n-2;i>=0;--i)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define FOREACH(n) for(auto it:n)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back


class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        ll answer=0;
        MPII mp;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        f1(i,0,n)
        {
            //Leaf Node
            int currentState=1;
            f1(j,0,i)
            {
                if(arr[i]%arr[j])continue;
                int firstNum=arr[j];
                int secondNum=arr[i]/arr[j];
                
                currentState=(currentState+(mp[firstNum]*mp[secondNum])%MOD)%MOD;
            }
                mp[arr[i]]=currentState;
                answer=(answer+currentState)%MOD;
        }
             return answer;
    }
};