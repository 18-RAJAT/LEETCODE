#define ll long long
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
#define FOR(a,b) for(int i=a;i<b;i++)
#define g __gcd(nums[0],nums[n-1])

class Solution {
public:
    int maximumsSplicedArray(vector<int>& n1, vector<int>& n2) {
        int mxd1=0,mxd2=0;
        int s1=0,s2=0,n=n1.size(),md1=0,md2=0,dp1=0,dp2=0;
        FOR(0,n){s1+=n1[i];s2+=n2[i];
        dp1=n2[i]-n1[i]+max(0,dp1);
        dp2=n1[i]-n2[i]+max(0,dp2);
        mxd1=max(mxd1,dp1);
        mxd2=max(mxd2,dp2);}
        return max(s1+mxd1,s2+mxd2);
    }
};