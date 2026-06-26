class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size(),p=n+1;
        long long ans=0;
        vector<int>fz(2*n+2),check(2*n+2);
        fz[p]=1,check[p]=1;
        for(auto& it:nums)
        {
            p+=(it==target?1:-1);
            fz[p]++;
            check[p]=check[p-1]+fz[p];
            ans+=check[p-1];
        }
        return ans;
    }
};