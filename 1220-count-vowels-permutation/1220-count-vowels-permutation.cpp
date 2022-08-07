#define MP make_pair
#define PB push_back
#define EPS 1e-9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define ll long long
#define read(type) readInt<type>()
const double pi=acos(-1.0);
const int INF = 1e9;
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
#define ff1(pass) for(long long int i=n-2;i>=0;--i)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define FOREACH(n) for(auto it:n)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back

const int num=2e4+1;
int dp[27][num];
class Solution {
public:
    int mod=1e9+7;
    int sol(int n,char c){
        if(n==0)return 1;
        if(dp[c-'a'][n]!=-1)return dp[c-'a'][n];
        int ans=0;
        if(c=='e'){
            ans+=sol(n-1,'a');
            ans%=mod;
            ans+=sol(n-1,'i');
            ans%=mod;
        }
        if(c=='a'){
            ans+=sol(n-1,'e');
            ans%=mod;
            ans+=sol(n-1,'i');
            ans%=mod;
            ans+=sol(n-1,'u');
            ans%=mod;
        }
        if(c=='i'){
            ans+=sol(n-1,'e');
            ans%=mod;
            ans+=sol(n-1,'o');
            ans%=mod;
        }
        if(c=='o'){
            ans+=sol(n-1,'i');
            ans%=mod;
        }
        if(c=='u'){
            ans+=sol(n-1,'i');
            ans%=mod;
            ans+=sol(n-1,'o');
            ans%=mod;
        }
        return dp[c-'a'][n]=ans;
    }
    int countVowelPermutation(int n) {
        memset(dp,-1,sizeof(dp));
        int ans=0;
        ans+=sol(n-1,'a');
        ans%=mod;
        ans+=sol(n-1,'e');
        ans%=mod;
        ans+=sol(n-1,'i');
        ans%=mod;
        ans+=sol(n-1,'o');
        ans%=mod;
        ans+=sol(n-1,'u');
        ans%=mod;
        return ans;
    }
};