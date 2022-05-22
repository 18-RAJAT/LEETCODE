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
    int countSubstrings(string s) {
        
           int n=s.size();
            int count=0;
            
            vector<vector<int>>dp(n,vector<int>(n,0));
            for(int gap=0;gap<n;++gap)
            {
                    for(int i=0,j=gap;j<n;++i,++j)
                    {
                            if(gap==0)
                            {
                                    count++;
                                    dp[i][j]=1;
                            }
                            else if(gap==1)
                            {
                                    if(s[i]==s[j])
                                    {
                                            dp[i][j]=1;count++;
                                    }
                            }
                            else
                            {
                                    if(s[i]==s[j] and dp[i+1][j-1]==1)
                                    {
                                            dp[i][j]=1;count++;
                                    }
                            }
                    }
            }
            return count;          
    }
};