class Solution {
public:
    int binarySearchOnLeftHalf(vector<int>&nums,int target)
    {
        int left=0,right=nums.size()-1;
        int res=-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]==target)
            {
                res=mid;
                right=mid-1;
            }
            else if(nums[mid]>target)
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        return res;
    }
    int binarySearchOnRightHalf(vector<int>&nums,int target)
    {
        int left=0,right=nums.size()-1;
        int res=-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]==target)
            {
                res=mid;
                left=mid+1;
            }
            else if(nums[mid]>target)
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=binarySearchOnLeftHalf(nums,target);
        int right=binarySearchOnRightHalf(nums,target);
        return {left,right};
    }
};