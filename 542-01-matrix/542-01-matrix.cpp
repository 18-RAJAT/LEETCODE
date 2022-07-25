#define MP make_pair
#define PB push_back
#define INF 1e9
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
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef queue<pair<int,int>> QU;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
#define ff(a,b) for(int i=a;i<b;i++)
#define f1(i,s,e) for(long long int i=s;i<e;i++)
#define ff1(pass) for(long long int i=n-2;i>=0;--i)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define vd vector<double>
#define mii map<long,long>
#define miid map<double,long>
#define si set<int>
#define sc set<char>
#define vi vector<int>


//dfs iterating  multiple times then use bfs

// class Solution {
// public:
//     void dfs(VII &matrix,VII &result,int i,int j,int currentDistance)
// {
//     if(i<0 or j<0 or i>=matrix.size() or j>=matrix[0].size()){return;}
//         if(currentDistance==0 or matrix[i][j]==1 and(result[i][j]==0 or result[i][j]>currentDistance))
//             {
//                 result[i][j]=currentDistance;
//                 dfs(matrix,result,i-1,j,currentDistance+1);
//                 dfs(matrix,result,i+1,j,currentDistance+1);
//                 dfs(matrix,result,i,j-1,currentDistance+1);
//                 dfs(matrix,result,i,j+1,currentDistance+1);
//             }
// }
//     vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
//         int n=matrix.size();
//         int m=matrix[0].size();
        
//         VII result(n,vi(m,0));
//         f1(i,1,n)
//         {
//             f1(j,1,m)
//             {
//                 if(matrix[i][j]==0)
//                 {
//                     dfs(matrix,result,i,j,0);
//                 }
//             }
//         }
//         return result;
//     }
// }; 



//use multisource BFS

class Solution{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vvi distance(n,vi(m,INF));
        QU q;
        // queue<pair<int,int>>q;
        f1(i,0,n)
        {
            f1(j,0,m)
            {
                if(grid[i][j]==0)
                {
                    distance[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        
        vi row{0,0,1,-1};
        vi col{-1,1,0,0};
        
        while(!q.empty())
        {
            auto temp=q.front();
            int x=temp.first;
            q.pop();
            int y=temp.second;
            f1(i,0,4)
            {
                int tp1=x+row[i];
                int tp2=y+col[i];
                if(tp1>=0 and tp1<n and tp2>=0 and tp2<m){
                    if(distance[tp1][tp2]>1+distance[x][y]){
                        distance[tp1][tp2]=1+distance[x][y];
                        q.push({tp1,tp2});
                    }
                }
            }
        }
        return distance;
    }    
};