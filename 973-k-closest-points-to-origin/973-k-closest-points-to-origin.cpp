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
typedef vector<PII> VIII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef priority_queue<pair<int,pair<int,int>>> PQVI;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
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
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        PQVI pq;
        // int n=points.size();
        // f1(i,0,n)
        FOREACH(points)
        {
            // int distance=points[i][0]*points[i][0]+points[1][1]*points[1][1];
            pq.push(make_pair(it[0]*it[0]+it[1]*it[1],make_pair(it[0],it[1])));
            // pq.push({distance,points[i]});
            if(pq.size()>k){pq.pop();}
        }
        VII answer;
        while(!pq.empty())
        {
            
            VI temp;
            // temp=pq.top();
            // answer.pb(temp.second);
            // pq.pop();
            temp.pb(pq.top().second.first);
            temp.pb(pq.top().second.second);
            answer.pb(temp);
            pq.pop();
        }
        return answer;
    }
};