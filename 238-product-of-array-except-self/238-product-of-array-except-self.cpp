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
#define vi vector<int>ans

static int fastio = []() {
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
     int n=nums.size();
            vi(n,1);
            f(1,n){ans[i]=ans[i-1]*nums[i-1];}
            int prev=1;
            for(int i=n-1;i>=0;--i)
            {
                    ans[i]*=prev;
                    prev*=nums[i];
                    // cout<<"Std";
            }
            return ans;
    }
};
