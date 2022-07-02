#define ll long long
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
#define f(a,b) for(int i=a;i<b;i++)
#define g __gcd(nums[0],nums[n-1])

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        // cout<<"gcd";
        int answer=g;
        return answer;
    }
};