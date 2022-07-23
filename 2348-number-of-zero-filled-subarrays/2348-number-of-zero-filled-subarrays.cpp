#define ll long long
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<vector<int>> VII;
typedef vector<string> VS;
typedef vector<PII> VIII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef unordered_map<char,int> MPC;
typedef set<int> SETI;
typedef multiset<int> MSETI;
#define ff for(int i=0;i<nums.size();i++)

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        ll res=0,count=0;
        ff
        {
          if(nums[i]==0){count++;}
            else{res+=(count*(count+1))/2;count=0;}
        }
        res=res+(count*(count+1))/2;
        return res;
    }
};