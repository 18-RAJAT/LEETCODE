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

class Solution {
public:
    VI frequency(string s)
{
        int n=s.size();
        VI v(26,0);
        f1(i,0,n)v[s[i]-'a']++;
        return v;
}
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int w1=words1.size(),w2=words2.size();
        VS result;
        VI countArr(26,0);
        f1(i,0,w2)
        {
            VI temp=frequency(words2[i]);
            f1(j,0,26)
            countArr[j]=max(countArr[j],temp[j]);
        }
        f1(i,0,w1)
        {
            bool flag=true;
            VI temp=frequency(words1[i]);
            f1(j,0,26)
            {
                if(temp[j]<countArr[j])
                {
                    flag=false;
                }
            }
            if(flag)
            {result.PB(words1[i]);}
        }
        return result;
    }
};