#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        ll ans=0;
        ll n=nums.size();
        ll mn,mx,cnt;
        mn=mx=cnt=0;
        for(ll i=0;i<n;++i)
        {
            if(nums[i]==minK)
            {
                mn=i;
            }
            if(nums[i]==maxK)
            {
                mx=i;
            }
            if(nums[i]<minK or nums[i]>maxK)
            {
                cnt=i+1;
                mn=mx=i;
            }
            if(nums[mn]==minK and nums[mx]==maxK)
            {
                ll min1=min(mn-cnt,mx-cnt)+1;
                ans+=min1;
            }
        }
        return ans;
    }
};