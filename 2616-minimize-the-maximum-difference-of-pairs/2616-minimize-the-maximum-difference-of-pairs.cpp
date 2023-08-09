class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        auto func=[&](int mid,vector<int>&nums,int k)->int
        {
            int count=0;
            for(int i=1;i<nums.size();++i)
            {
                if(nums[i]-nums[i-1]<=mid)
                {
                    i++;
                    count++;
                }
            }
            return k<=count;
        };
        sort(nums.begin(),nums.end());
        int l(0),r(INT_MAX);
        int ans(-1);
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(func(m,nums,p))
            {
                ans=m;
                r=m-1;
            }
            else
            {
                l=m+1;
            }
        }
        return ans;
    }
};