#define MP make_pair
#define INF (int)1e9
#define EPS 1e-9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define ll long long
#define all(x) sort(x.begin(), x.end())
#define ff(a,b) for(int i=a;i<b;i++)
#define f1(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define FOREACH(n) for(auto it:n)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<vector<int>> VII;
typedef vector<string> VS;
typedef vector<vector<string>> VVS;
typedef vector<PII> VIII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef priority_queue<pair<int,pair<int,int>>> PQVI;
typedef unordered_map<string,vector<string>> MPSVS;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        // f1(i,0,n)
        // {
        //     f1(j,i+1,n)
        //     {
        //         f1(k,j+1,n)
        //         {
        //             if(nums[i]<nums[j]<nums[k])
        //             {
        //                 return true;
        //             }
        //         }
        //     }
        // }
        // return false;
        // f1(i,0,n)
        // {
        //     f1(j,i+1,n)
        //     {
        //         f1(k,j+1,n)
        //         {
        //             if(nums[i]<nums[k])
        //             {
        //                 return true;
        //             }
        //             else if(nums[j]<nums[k])
        //             {
        //                 return true;
        //             }
        //             else if(nums[k]>nums[i])
        //             {
        //                 return true;
        //             }
        //         }
        //     }
        // }
        // return false;
        
        // if(n<2)
        // {
        //     return false;
        // }
        int f=INT_MAX,l=INT_MAX;
        f1(i,0,n)
        {
            if(nums[i]<f)
            {
                f=nums[i];
            }
            else if(nums[i]>f and nums[i]<l)
            {
                l=nums[i];
                // return true;
            }
            else if(nums[i]>l)
            {
                return true;
            }
        }
        return false;
    }
};