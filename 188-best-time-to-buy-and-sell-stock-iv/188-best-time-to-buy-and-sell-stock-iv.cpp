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


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if(k==0 or n==0 or n==1)return 0;
        VII dp(k+1,VI(n));
        int x=dp.size();int y=dp[0].size();
        f1(i,0,x)
        {
            f1(j,0,y)
            {
                if(i==0)dp[i][j]=0;
                else if(j==0)dp[i][j]=0;
                else
                {
                    int value;
                    int maximumProfit=INT_MIN;
                    f1(k,0,j)
                    {
                        value=prices[j]-prices[k]+dp[i-1][k];
                        maximumProfit=max(value,maximumProfit);
                    }
                    dp[i][j]=max(dp[i][j-1],maximumProfit);
                }
            }
        }
            return dp[x-1][n-1];
    }
};