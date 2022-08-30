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
typedef vector<ll> VI;
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
#define ff1(pass) for(long long int i=n-2;i>=0;--i)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define FOREACH(n) for(auto it:n)
#define rf(i,e,s) for(ll i=n-1;i>0;i--)
#define pb push_back
#define eb emplace_back


class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        ll n=nums.size(),answer=1;
        VI prefix(n+1,0);
        f1(i,0,n)
        prefix[i+1]=prefix[i]+nums[i];
        
         rf(i,n-1,0)
        {
            ll value=nums[i];
            ll s=0,e=i-1,idx=-1;
            
            while(s<=e)
            {
                ll m=(s+e)/2;
                if((value*i-prefix[i+1])+value<= k-(prefix[m]-value*m)){idx=m;e=m-1;}
                else{s=m+1;}
            }
            if(idx!=-1)answer=max(answer,i-idx+1);
        }
        return answer;
    }
};