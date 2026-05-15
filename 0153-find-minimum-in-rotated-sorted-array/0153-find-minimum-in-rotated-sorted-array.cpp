class Solution {
public:
    int findMin(vector<int>& nums) {
        int start=0,n=nums.size(),end=n-1,mid;
        while(start<=end)
        {
            mid=(start+end)/2;

            if(nums[mid]>=nums[end])
            {
                start=mid+1;
            }
            else
            {
                end=mid;
            }
        }
        return nums[mid];
    }
};