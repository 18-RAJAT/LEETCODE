class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i+2*k<=n;++i)
        {
            int f=1,s=1;
            for(int j=0;j<k-1;++j)
            {
                if(nums[i+j]>=nums[i+j+1])f=0;
            }
            if(!f)continue;
            for(int j=0;j<k-1;++j)
            {
                if(nums[i+k+j]>=nums[i+k+j+1])s=0;
            }
            if(s)return true;
        }
        return false;
    }
};