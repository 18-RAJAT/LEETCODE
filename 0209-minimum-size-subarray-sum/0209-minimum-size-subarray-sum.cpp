class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        function<bool(int&,vector<int>&,int&)>binarySearch=[&](int&target,vector<int>&nums,int&mid)->bool
        {
            int sum=0;
            for(int i=0;i<mid;++i)
            {
                sum+=nums[i];
            }
            if(sum>=target)
            {
                return true;
            }
            int pos=0;
            for(int i=mid;i<nums.size();)
            {
                sum-=nums[pos++];
                sum+=nums[i++];
                if(sum>=target)
                {
                    return true;
                }
            }
            if(sum<=target)
            {
                return false;
            }
            return true;
        };
        int start=1,end=nums.size();
        int ans=0;
        int mid=0;
        
        while(start<=end)
        {
            mid=start+(end-start)/2;
            if(binarySearch(target,nums,mid))
            {
                ans=mid;
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        // cout<<binarySearch(target,nums,mid)<<"\n";
        return ans;
    }
};