// ----------------------</BITWISE>-------------------------- 
/* a=target variable, b=bit number to act upon 0-n */
#define BIT_SET(a,b) ((a) |= (1ULL<<(b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))

// '!!' to make sure this returns 0 or 1
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b))))

#define BITMASK_SET(x, mask) ((x) |= (mask))
#define BITMASK_CLEAR(x, mask) ((x) &= (~(mask)))
#define BITMASK_FLIP(x, mask) ((x) ^= (mask))
#define BITMASK_CHECK_ALL(x, mask) (!(~(x) & (mask)))
#define BITMASK_CHECK_ANY(x, mask) ((x) & (mask))
#define LSB_ANY(n) (n&(n-1))
#define LSB_CHECK(n) (n&(-n))
// ----------------------</BITWISE END>--------------------------


#define sza(x) ((int)x.size())
#define MP make_pair
#define INF (int)1e9
#define MOD 1000000007
#define ll long long
#define MEM(a, b) memset(a, (b), sizeof(a))
#define all(x) sort(x.begin(), x.end())
#define ff(a,b) for(int i=a;i<b;i++)
#define f1(i,s,e) for(int i=s;i<e;i++)
#define cf(i,s,e) for(int i=s;i<=e;i++)
#define FOREACH(n) for(auto it:n)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define revs(x,y,z) for(ll i=x;i<=y;i+=z)
#define pb push_back
#define eb emplace_back
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<vector<int>> VII;
typedef vector<string> VS;
typedef vector<vector<string>> VVS;
typedef vector<PII> VIII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef priority_queue<pair<int,pair<int,int>>> PQVI;
typedef set<int> SETI;
typedef multiset<int> MSETI;
#define INS insert
#define IN(A, B, C) assert( B <= A && A <= C)

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int n=sza(nums);
        int pref[n+1];MEM(pref,0);
        
        auto prefix=[&]()->void
        {
            cf(i,1,n)
            {
                pref[i]=pref[i-1]+nums[i-1];
            }
        };
        
        prefix();
        int ans=0;
        cf(i,0,n)
        {
            int l=0,r=n;
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(pref[mid]-pref[i]+k>=mid-i)
                {  
                    ans=max(ans,mid-i);
                    mid++;
                    l=mid;
                }
                else
                {
                    mid--;
                    r=mid;
                }
            }
        }
        return ans;
    }
};