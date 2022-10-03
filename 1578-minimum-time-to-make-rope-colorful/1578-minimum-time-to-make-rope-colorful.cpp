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
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;


class Solution {
public:
   public:
    
    int minCost(string colors, vector<int>& nt) {
        // int n=colors.size();
        // int dp[n][3];
        // dp[0][0]=nt[0];
        // dp[0][1]=nt[1];
        // dp[0][2]=nt[2];
        // f1(i,1,n)
        // {
        //     if(colors[i]=='a')
        //     {
        //         dp[i][0]=min(dp[i-1][1],dp[i-1][2]);
        //         dp[i][1]=min(dp[i-1][0],dp[i-1][2])+nt[1];
        //         dp[i][2]=min(dp[i-1][0],dp[i-1][1])+nt[2];
        //     }
        //     else if(colors[i]=='b')
        //     {
        //         dp[i][0]=min(dp[i-1][1],dp[i-1][2])+nt[0];
        //         dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
        //         dp[i][2]=min(dp[i-1][0],dp[i-1][1])+nt[2];
        //     }
        //     else
        //     {
        //         dp[i][0]=min(dp[i-1][1],dp[i-1][2])+nt[0];
        //         dp[i][1]=min(dp[i-1][0],dp[i-1][2])+nt[1];
        //         dp[i][2]=min(dp[i-1][0],dp[i-1][1]);
        //     }
        // }
        // return min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]));
        
        
        //TLE
        
//         int n=colors.size();
//         int mini=0;
//         f1(i,1,n)
//         {
//             if(colors[i]==colors[i-1])
//             {
//                 int sum=nt[i-1];
//                 int maximum=nt[i-1];
                
//                 while(colors[i-1]==colors[i])
//                 {
//                     sum+=nt[i];
                    
//                     if(maximum<nt[i])
//                     {
//                         maximum=nt[i];
//                         i++;
//                     }
//                 }
//                 mini+=(sum-maximum);
//             }
//         }
//         return mini;
        
        int n=colors.size();
        int miniCost=0,i=0;
        while(i<n-1)
        {
            char ch=colors[i];
            int totalSum=nt[i];
            int mxVal=nt[i];
            while(i<n-1 and colors[i]==colors[i+1])
            {
                totalSum+=nt[i+1];
                mxVal=max(mxVal,nt[i+1]);i++;
            }
            miniCost+=(totalSum-mxVal);i++;
        }
        return miniCost;
    }
};