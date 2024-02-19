class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        function<int(vector<int>&,int)>func=[&](vector<int>& nums,int k)->int
        {
            int n=nums.size();
            map<int,int>subarrays;
            int ans=0;
            for(int i=0,j=0;j<n;++j)
            {
                if(subarrays[nums[j]]==0)
                {
                    k--;
                }
                subarrays[nums[j]]++;
                while(k<0)
                {
                    subarrays[nums[i]]--;
                    if(subarrays[nums[i]]==0)
                    {
                        k++;
                    }
                    i++;
                }
                ans+=j-i+1;
            }
            return ans;
        };
        return func(nums,k)-func(nums,k-1);
    }
};