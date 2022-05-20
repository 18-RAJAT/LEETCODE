#define ll long long
#define f(a,b) for(int i=a;i<b;i++)
#define f2(x,a,b) for(int x=a;x<b;x++)
#define fr(b,a) for(int i=b;i>=a;i--)
#define fit(nums) for(auto &it:nums)
#define v vector
#define p priority_queue
#define um unordered_map
#define us unordered_set
#define pb push_back
#define ppb pop_back
#define TN TreeNode
#define LN ListNode
static int fastio = []() {
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[n][m];
            for(int i=0;i<n;++i)
            {
                    for(int j=0;j<m;++j)
                    {
                            if(i==0 or j==0){dp[i][j]=1;}
                            else{dp[i][j]=dp[i-1][j]+dp[i][j-1];}
                    }
            }
            return dp[n-1][m-1];
    }
};