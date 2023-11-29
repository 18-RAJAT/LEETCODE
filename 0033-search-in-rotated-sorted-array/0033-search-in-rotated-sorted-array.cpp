class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int left_half=0;
        int right_half=n-1;
        while(left_half<=right_half)
        {
            int mid=left_half+(right_half-left_half)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]>=nums[left_half])
            {
                if(target>=nums[left_half] && target<nums[mid])//range [left_half,mid)
                {
                    right_half=mid-1;
                }
                else
                {
                    left_half=mid+1;
                }
            }
            else
            {
                if(target>nums[mid] && target<=nums[right_half])//range (mid,right_half]
                {
                    left_half=mid+1;
                }
                else
                {
                    right_half=mid-1;
                }
            }
        }
        return -1;
    }
};