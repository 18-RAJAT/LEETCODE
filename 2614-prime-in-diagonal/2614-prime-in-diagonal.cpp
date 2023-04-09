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


template<class T> bool chmax(T &a, T b) {
	if (a >= b) return false;
	a = b; return true;
}
template<class T> bool chmin(T &a, T b) {
	if (a <= b) return false;
	a = b; return true;
}

#define sza(x) ((int)x.size())
#define MP make_pair
#define INS insert
#define PB push_back
#define PF push_front
#define EM emplace
#define EB emplace_back
#define MEM(a, b) memset(a, (b), sizeof(a))
#define INF (int)1e9
#define MOD 1000000007
#define ll long long
#define all(x) sort(x.begin(), x.end())
#define ff(a,b) for(int i=a;i<b;i++)
#define f1(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
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
    int diagonalPrime(vector<vector<int>>& nums) {
        int n=sza(nums);
        int m=sza(nums[0]);
        int ert=0;
        function<bool(int)>PRIME=[&](int x)->bool
        {
            if(x<=1)
            {
                return false;
            }
            for(int i=2;i*i<=x;i++)
            {
                if(x%i==0)
                {
                    return false;
                }
            }
            return true;
        };
        f1(i,0,n)
        {
            // f1(j,0,m)
            // {
                if(PRIME(nums[i][i]))
                {
                    ert=max(ert,nums[i][i]);
                }
            // }
        }
        f1(i,0,n)
        {
            if(PRIME(nums[i][m-i-1]))
            {
                ert=max(ert,nums[i][m-i-1]);
            }
        }
        return ert;
    }
};