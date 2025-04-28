class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n=nums.size();
        long long ans=0,sum=0;
        int i=0,j=0;
        while(j<n) 
        {
            sum+=nums[j];
            while(i<=j && k<=sum*(j-i+1)) 
            {
                sum-=nums[i];
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
};