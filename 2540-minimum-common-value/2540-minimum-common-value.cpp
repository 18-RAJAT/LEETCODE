class Solution {
    public:
    int binary_search(vector<int>&nums,int left,int right,int target)
    {
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]<target)
            {
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
        return -1;
    }
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int left=0;
        int right=nums2.size()-1;
        int result=-1;
        for(int& num:nums1)
        {
            int index=binary_search(nums2,left,right,num);
            if(index!=-1 && (result==-1 || num<result))
            {
                result=num;
            }
        }
        return result;
    }
};