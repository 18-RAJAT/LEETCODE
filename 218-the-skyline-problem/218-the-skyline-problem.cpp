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
typedef priority_queue<VI> PQVVI;
typedef unordered_map<string,vector<string>> MPSVS;
typedef map<int,vector<pair<int,int>>> mivpii;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;


class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        PQVVI pq;
        mivpii m;
        VII ans;
        int count=0,width=0;
        for(auto i:buildings)
        {
            m[i[0]].pb({i[2],i[1]});
            m[i[1]].pb({0,0});
        }
        for(auto i:m)
        {
            auto res=i.second;   
            for(auto j : res){
                if(j.first!=0){
                    pq.push({j.first, j.second});
                }    
            }
            if(i.first == width){
                count = 0;
            }
            while(!pq.empty() && pq.top()[1]<=i.first){
                pq.pop();
            }
            if(!pq.empty() && pq.top()[0]>count){
                count = pq.top()[0];
                width = pq.top()[1];
                ans.pb({i.first,count});
            }
            else if(count == 0)
            {
                ans.pb({i.first, 0});
            }       
        }  
        
        VII res;
        int prev=-1;
        for(auto i:ans)
        {
            if(i[1]!=prev)
            {
                res.pb(i);
                prev=i[1];
            }
        }
        return res;
    }
};