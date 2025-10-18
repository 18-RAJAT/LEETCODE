class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long mn=LLONG_MIN;
        int ans=0;
        for(auto& it:nums)
        {
            long long l=(long long)it-k,r=(long long)it+k;
            if(mn<l)mn=l;
            if(mn<=r)ans++,mn++;
        }
        return ans;
    }
};