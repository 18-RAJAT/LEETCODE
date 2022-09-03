#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define MOD 1000000007
#define ll long long
#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()
const double pi=acos(-1.0);
typedef queue<pair<int,int>> QPII;
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

// class Solution {
// public:
    // vector<int>result;
    // vector<int> numsSameConsecDiff(int n, int k) {
//         if(n==2 and k==1)
//         {return{10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98};}
        
//         if(n==1)
//         {return{0,1,2,3,4,5,6,7,8,9};}
//         QPII q;
//         cf(i,1,9)
//         {q.push(make_pair(i,1));}
        
//         PII value;
//         while(!q.empty())
//         {
//             int m=value.first;
//             int x=value.second;
//             value=q.front();q.pop();
            
//             if(x==n){result.pb(m);}
            
//             int endValue=m%10;
           
//             if(endValue-k>=0 and x<n)
//             {q.push({m*10+endValue-k,x+1});}
            
//             if(endValue+k<=9 and x<n)
//             {q.push({m*10+endValue+k,x+1});}
//         }
//         return result;   
//     }
// };


class Solution 
{
public:
    
    void dfs(int length,string num,VI &result,int k,int n,int previous)
    {
        if(length==n)
        {
            int cons=stoi(num);
            result.pb(cons);return;
        }
        cf(i,0,9)
        {
            if(length==0 and i==0){continue;}
            if(abs(i-previous)==k or length==0)
            {char ch=i+48;dfs(length+1,num+ch,result,k,n,i);}
        }
    }
    vector<int>numsSameConsecDiff(int n,int k) 
    {
        VI v;
        dfs(0,"",v,k,n,0);
        return v;
    }
};