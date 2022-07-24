#define ll long long
typedef vector<pair<int,int>> vv;
typedef pair<int, int> PII;
typedef pair<int,int> PAIR;
typedef vector<int> VI;
typedef vector<vector<int>> VII;
typedef vector<string> VS;
typedef vector<PII> VIII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef unordered_map<char,int> MPC;
typedef map<int,vector<int>> mvi;
typedef set<int> SETI;
typedef map<vector<int>,int> mpii;
typedef multiset<int> MSETI;
// #define f(a,b) for(int i=0;i<n;++i)
// #define fff(a,b) for(int i=0;i<m;++i)
#define pb push_back
#define PB pop_back

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        // mpii v1,v2;
        // int ans=1;
        // for(auto it:grid){v1[it]++;}
        // for(auto it:v1){if(it.second!=0){if(v2[it.first]!=0)ans+=it.second*v2[it.first];}}
        // return ans;
        
        int ans=0;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                bool flag=0;
                for(int k=0;k<n;++k)
                {
                    if(grid[i][k]!=grid[k][j]){flag=1;}
                }
                if(flag==0){ans++;}
            }
        }
        return ans;
    }
};