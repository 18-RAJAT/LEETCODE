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
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int>> VII;
typedef vector<string> VS;
typedef vector<vector<string>> VVS;
typedef vector<PII> VIII;
typedef vector<vi> VVI;
typedef map<int,int> MPII;
typedef priority_queue<pair<int,pair<int,int>>> PQVI;
typedef unordered_map<string,vector<string>> MPSVS;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<bool>bit(n+1,false);
        
        vector<int>ans;
        for(auto n:nums)
        {
            if(bit[n]==true)
                ans.pb(n);
            bit[n]=true;
        }
        cf(i,1,n)
        {
            if(bit[i]==false)
                ans.pb(i);
        }
        return ans;
    }
};