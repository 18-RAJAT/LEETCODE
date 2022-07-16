class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n=nums.size();
        bool inc=true,dec=true;
        for(int i=1;i<n;++i)
        {if(nums[i]<nums[i-1]){inc=false;}}
        for(int i=1;i<n;++i)
        {if(nums[i]>nums[i-1]){dec=false;}}
        return(inc or dec);
    }
};
