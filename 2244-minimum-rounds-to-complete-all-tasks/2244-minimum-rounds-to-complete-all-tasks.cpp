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
#define nl endl
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

class Solution {
public:
    int minimumRounds(vector<int>& task) {
        int n=task.size();
        int temp;int ct=0;
//         // sort(all(task));
//         sort(task.begin(),task.end());
        int ans=0;
//         int low=0,high=0;
        
//         while(low<n)
//         {
//             high=low;
//             while(high<n and task[high]==task[low])
//             {
//                 high++;
//             }
//             // cout<<high<<nl;
            
//             temp=high-low;
//             if(temp<2)
//             {
//                 return -1;
//             }
//             // cout<<temp<<nl;
//             ct+=temp/3+(temp%3>0?1:0);
//             // cout<<ct<<nl;
//         }
//         return ct;
       MPII mp;
        for(auto it:task)
            mp[it]++;
        for(auto it:mp)
        {
            if(it.second==1)
            {
                return -1;
            }
            ans+=(it.second+2)/3;
        }
        return ans;
    }
};