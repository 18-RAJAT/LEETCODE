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

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        f1(i,0,n-1)
        {
            int m=mat[i].size();
            f1(j,0,m-1)
            {
                if(mat[i][j]!=mat[i+1][j+1])
                {
                    return false;
                }
            }
        }
        return true;
    }
};