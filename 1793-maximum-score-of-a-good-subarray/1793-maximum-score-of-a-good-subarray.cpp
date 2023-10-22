class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=nums[k];
        int mn=nums[k];
        int i=k;
        int j=k;
        while(i>0 || j<n-1)
        {
            if(i==0)
            {
                j++;
                mn=min(mn,nums[j]);
            }
            else if(j==n-1)
            {
                i--;
                mn=min(mn,nums[i]);
            }
            else if(nums[i-1]>nums[j+1])
            {
                i--;
                mn=min(mn,nums[i]);
            }
            else
            {
                j++;
                mn=min(mn,nums[j]);
            }
            ans=max(ans,mn*(j-i+1));
        }
        return ans;      
    }
};