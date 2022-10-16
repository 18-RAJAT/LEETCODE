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
typedef map<int,int> MPII;
typedef priority_queue<pair<int,pair<int,int>>> PQVI;
typedef unordered_map<string,vector<string>> MPSVS;


class Solution {
public:
    int minDifficulty(vector<int>& jd, int d) {
        int n=jd.size();
        if(n<d)
        {
            return -1;
        }
        VVI dp(d,VI(n,INT_MAX));
        dp[0][0]=jd[0];
        f1(i,1,n)
        {
            dp[0][i]=max(dp[0][i-1],jd[i]);
        }
        f1(i,1,d)
        {
            f1(j,i,n)
            {
                int mx=jd[j];
                // rf(k,j,i)
                for (int k=j;k>=i;--k)
                {
                    mx=max(mx,jd[k]);
                    dp[i][j]=min(dp[i][j],dp[i-1][k-1]+mx);
                }
            }
        }
        return dp[d-1][n-1];
    }
};