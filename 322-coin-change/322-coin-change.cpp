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
    int coinChange(vector<int>& coins, int amount) {
        
            int n=coins.size();
            int dp[n+1][amount+1];
            
            for(int i=0;i<=n;++i)
            {
                    for(int j=0;j<=amount;++j)
                    {
                            if(j==0){dp[i][j]=0;}
                            else if(i==0){dp[i][j]=1e5;}
                            else if(coins[i-1]>j){dp[i][j]=dp[i-1][j];}
                            else{dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);}
                    }
            }
            return dp[n][amount]>1e4?-1:dp[n][amount];
    }
};