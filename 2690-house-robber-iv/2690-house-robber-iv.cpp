class Solution {
public:
    bool recur(vector<int>&nums,int mid,int k)
    {
        int n=nums.size(),count=0;
        for(int i=0;i<n;++i)
        {
            if(nums[i]<=mid)count++,i++;
        }
        return count>=k;
    }
    int minCapability(vector<int>& nums, int k) {
        int left=1,right=*max_element(nums.begin(),nums.end()),ans=right;
        while(left<=right)
        {
            int mid=(left+right)/2;
            (recur(nums,mid,k))?ans=mid,right=mid-1:left=mid+1;
        }
        return ans;
    }
};