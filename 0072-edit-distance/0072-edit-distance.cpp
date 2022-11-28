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

class Solution {
public:
//     int editDistance(string s1,string s2,vector<vector<int>>answer)
//     {
//         int n=s1.size();
//         int m=s2.size();
        
//         if(n==0 or m==0)
//         {
//             int mx=max(n,m);
//             return mx;
//         }
//         else
//         {
            
//         }
    // }
    
    int minDistance(string word1, string word2) {
        /*
            w1=alice
            w2=bob
            
            replace a with b 
            replace l with o
            replace i with b
            
            then remove c and e
            same string=bob and count is 3
        */
        int n=word1.length();
        int m=word2.length();
        
        int dp[n+1][m+1];
        // memset(dp,0,sizeof(dp));
        
        // string temp1=word1;
        // string temp2=word2;

        cf(i,0,n)
        {
            cf(j,0,m)
            {
                //no words are present in word1 string
                if(i==0)
                {
                    dp[i][j]=j;
                }
                //no words are present in word2 string
                else if(j==0)
                {
                    dp[i][j]=i;
                }
                else if(i==0 and j==0)
                {
                    return {};
                }
                // else if(!i and !j)
                // {
                //     return 0;
                // }
                else if(word1[i-1]==word2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                // else if(temp1==word2 and temp2=word1)
                // {
                //     return 1;
                // }
                else
                {
                    //finding minimum
                    dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                }
            }
        }
        return dp[n][m];
    }
};