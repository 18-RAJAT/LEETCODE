typedef long long ll;
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        ll res=0;
        ll sum=0;
        for(ll i=0;i<nums.size();++i)
        {
            sum+=nums[i];
            res=max((sum+i)/(i+1),res);
        }
        return res;
    }
};