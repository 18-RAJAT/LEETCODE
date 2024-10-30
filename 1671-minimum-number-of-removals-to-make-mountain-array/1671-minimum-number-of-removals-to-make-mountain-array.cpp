class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int m=nums.size();
        vector<int>left(m,1),right(m,1);
        for(int i=1;i<m;++i)
        {
            for(int j=0;j<i;++j)
            {
                if(nums[i]>nums[j])left[i]=max(left[i],left[j]+1);
            }
        }
        for(int i=m-2;~i;--i)
        {
            for(int j=m-1;j>i;--j)
            {
                if(nums[i]>nums[j]) right[i]=max(right[i],right[j]+1);
            }
        }
        int ans=m;
        for(int i=1;i<m-1;++i)
        {
            if(left[i]>1 && right[i]>1)ans=min(ans,m-(left[i]+right[i]-1));
        }
        return ans;
    }
};