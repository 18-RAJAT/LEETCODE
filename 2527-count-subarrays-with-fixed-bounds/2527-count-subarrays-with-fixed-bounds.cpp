class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long int n=nums.size();
        long long int ans=0,mn=-1,mx=-1,res=-1;
        for(int i=0;i<n;++i)
        {
            if(nums[i]==minK)mn=i;
            if(nums[i]==maxK)mx=i;
            if(nums[i]<minK || nums[i]>maxK)res=i;
            int chk=min(mn,mx);
            if(res<=chk)ans+=chk-res;
        }
        return ans;
    }
};