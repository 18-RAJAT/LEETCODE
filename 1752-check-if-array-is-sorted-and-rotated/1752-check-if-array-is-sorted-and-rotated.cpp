class Solution {
public:
    bool check(vector<int>& nums) {
        int ert=0;
        int n=nums.size();
        for(int i=0;i<n;++i)
        {
            int idx=(i+1)%n;
            if(nums[idx]<nums[i])
            {
                ert++;
            }
        }
        return ert<=1?true:false;
    }
};