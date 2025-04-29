class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int mx=*max_element(nums.begin(),nums.end());
        long long ans=0;
        int count=0,i=0,j=0;
        while(j<n)
        {
            count+=(nums[j]==mx);
            while(i<=j && count>=k)
            {
                ans+=(n-j);
                count-=(nums[i]==mx);
                i++;
            }
            j++;
        }
        return ans;
    }
};