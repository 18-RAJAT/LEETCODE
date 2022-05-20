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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacle) {
        
            int row=obstacle.size();
            int column=obstacle[0].size();
            int dp[row][column];
            bool flag=false;
            
            //1st row
            for(int i=0;i<column;++i)
            {
                    if(flag or obstacle[0][i]==1)
                    {
                            flag=true;
                            dp[0][i]=0;
                    }
                    else
                    {
                            dp[0][i]=1;
                    }
                    cout<<"run";
            }
            
            //1st column
            flag = false;
            for(int i=0;i<row;++i)
            {
                    if(flag or obstacle[i][0]==1)
                    {
                            flag=true;
                            dp[i][0]=0;
                    }
                    else
                    {
                            dp[i][0]=1;
                    }
                    cout<<"Testing";
            }
            
            for(int i=1;i<row;++i)
            {
                    for(int j=1;j<column;++j)
                    {
                         if(obstacle [i][j]==1){dp[i][j]=0;}
                            else
                            {
                                 dp[i][j]=dp[i-1][j]+dp[i][j-1];
                            }
                    }
            }
            return dp[row-1][column-1];
    }
};