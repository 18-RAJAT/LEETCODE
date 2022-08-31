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
typedef vector<bool> VB;
typedef vector<vector<string>> VVS;
typedef vector<vector<bool>> VVB;
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
#define f1(i,s,e) for(int i=s;i<e;i++)
#define ff1(pass) for(int i=n-2;i>=0;--i)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define FOREACH(n) for(auto it:n)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back

class Solution {
public:
    
    void dfs(int r,int c,VVB &visited,int previous,VVI &heights)
    {
        if(r<0 or r>=heights.size() or c<0 or c>=heights[0].size()){return;}
        if(visited[r][c] or heights[r][c]<previous){return;}
        visited[r][c]=true;
        
        dfs(r+1,c,visited,heights[r][c],heights);
        dfs(r-1,c,visited,heights[r][c],heights);
        dfs(r,c+1,visited,heights[r][c],heights);
        dfs(r,c-1,visited,heights[r][c],heights);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row=heights.size();
        int col=heights[0].size();
        VVB pacific(row,VB(col,false));
        VVB atlantic(row,VB(col,false));
        
        f1(i,0,col)
        {
            dfs(0,i,pacific,INT_MIN,heights);
            dfs(row-1,i,atlantic,INT_MIN,heights);
        }
        
        f1(j,0,row)
        {
            dfs(j,0,pacific,INT_MIN,heights);
            dfs(j,col-1,atlantic,INT_MIN,heights);
        }
        
        VII answer;
        f1(R,0,row)
        {
            f1(C,0,col)
            {
                if(pacific[R][C] and atlantic[R][C]){answer.pb({R,C});}
            }
        }
        return answer;
    }
};