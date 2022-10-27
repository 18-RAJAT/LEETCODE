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
typedef vector<vector<int>>vii;
typedef vector<vector<char>>vvc;
typedef vector<string> VS;
typedef vector<vector<string>> VVS;
typedef vector<PII> VIII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef priority_queue<pair<int,pair<int,int>>> PQVI;
typedef unordered_map<string,vector<string>> MPSVS;
typedef set<int> SETI;
typedef multiset<int> MSETI;


class Solution {
public:
    bool helper(vvc& grid)
    {
        f1(i,0,9)
        {
            f1(j,0,9)
            {
                
                if(grid[i][j]=='.')
                {
                    for(char c='1';c<='9';c++)
                    {
                        
                        if(isValid(c,i,j,grid))
                        {
                            grid[i][j]=c;
                        
                        
                        if(helper(grid)==true)
                        {
                            return true;
                        }
                        else
                        {
                            grid[i][j]='.';
                        }
                            
                        }
                    }
                return false;
                }
            }
        }
        return true;
    }
    bool isValid(char c,int row,int col,vvc grid){
        f1(i,0,9)
        {
            
            if(grid[row][i]==c)
            {
                return false;
            }
            
            if(grid[i][col]==c)
            {
                return false;
            }
            
            if(grid[3*(row/3)+i/3][3*(col/3)+i%3]==c)
            {
                return false;
            }
        }
        return true;
    }
    void solveSudoku(vvc& board) 
    {
        helper(board);
    }
};