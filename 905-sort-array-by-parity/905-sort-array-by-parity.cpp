class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        for(int i=0,CurrentEven=0;i<nums.size();++i)
        {
            if(nums[i] % 2 == 0)
            {
             swap(nums[i],nums[CurrentEven++]);
        
            }

        }
        return nums;
    }
};