#define ll long long
#define f(i,a,b) for(int i=a;i<b;i++)
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
    int jump(vector<int>& nums) {
        
         int n=nums.size();
         int jumps=0;
         int mxreach=0;
         int current=0;
            for(int i=0;i<nums.size()-1;++i)
            {
                    mxreach=max(mxreach,i+nums[i]);
                    if(i==current){jumps++;current=mxreach;}
            }
            return jumps;
    }
};