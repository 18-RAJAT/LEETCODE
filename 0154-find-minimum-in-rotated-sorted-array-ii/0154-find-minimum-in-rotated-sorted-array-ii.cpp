class Solution{
public:
    int findMin(vector<int>&nums){
        int n=nums.size(),l=0,r=n-1;
        int ans=INT_MAX;
        while(l<=r)
        {
            int mid=(l+r)/2;
            ans=min({ans,nums[l],nums[mid],nums[r]});
            if(nums[mid]<nums[r])
            {
                r=mid-1;
            }
            else if(nums[mid]>nums[r])
            {
                l=mid+1;
            }
            else
            {
                l++,r--;
            }
        }
        return ans;
    }
};