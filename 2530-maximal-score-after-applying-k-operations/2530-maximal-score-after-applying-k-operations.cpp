#define ll long long
typedef pair<int,int> PII;
typedef vector<long long> VI;
typedef vector<bool> VB;
typedef vector<char> VC;
typedef vector<char> VC;
typedef vector<vector<long long>> VII;
typedef vector<pair<ll,ll>>VPII;
typedef vector<string> VS;
typedef vector<PII> VIII;
typedef vector<VI> VVI;
// typedef vector<string> VS;
typedef map<ll,ll> MPII;
typedef map<char,int> MPCI;
typedef priority_queue<ll> PQ;
typedef map<string,int> MPSI;
typedef set<long long> seti;
typedef multiset<int> MSETI;
typedef priority_queue<pair<int,int>> PQPII;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
#define nl endl
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        PQ p;
        for(auto it:nums)
        {
            p.push(it);
        }
        ll ans=0;
        while(k--)
        {
            ll tp=p.top();
            p.pop();

            ans+=tp;
            
            tp=(tp-1)/3+1;
            p.push(tp);
            // k--;
        }
        return ans;
    }
};