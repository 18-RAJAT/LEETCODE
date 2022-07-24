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
typedef multiset<int> MSETI;
#define ff(a,b) for(int i=0;i<n;++i)
#define pb push_back
#define PB pop_back

class Solution {
public:
    char repeatedCharacter(string s) {
       MPC m;
        int n=s.size();
        for(int i=0;i<n;++i)
        {
            m[s[i]]++;
            for(auto it:m)
            {
                if(it.second==2){return it.first;}
            }
        }
        return ' ';
    }
};