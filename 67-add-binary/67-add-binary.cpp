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
    string addBinary(string a, string b) {
        
          int n=a.length()-1;int m=b.length()-1;
            string answer;
            int carry=0;
            while(n>=0 or m>=0 or carry)
            {
                    if(n>=0){carry=carry+a[n]-'0';n--;}
                    if(m>=0){carry=carry+b[m]-'0';m--;}
                    
                    answer+=(carry%2+'0');carry=carry/2;
            }
            reverse(answer.begin(),answer.end());
            return answer;
    }
};