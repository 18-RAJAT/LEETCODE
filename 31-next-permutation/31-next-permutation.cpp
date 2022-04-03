class Solution {
public:
    
    void nextPermutation(vector<int>& nums) {
        
        //Initialize variable
        int Breakpoint = -1;
        
        for(int i=nums.size()-1;i>0;--i)
        {
            if(nums[i] > nums[i-1])
            {
                Breakpoint = i-1;
                break;
            }
        }
        
        if(Breakpoint < 0)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        
        for(int i=nums.size()-1;i>0;--i)
        {
            if(nums[i] > nums[Breakpoint])
            {
                swap(nums[Breakpoint],nums[i]);
                
                reverse(nums.begin() + Breakpoint + 1, nums.end());
                
                break;
            }
        }
        
    }
};