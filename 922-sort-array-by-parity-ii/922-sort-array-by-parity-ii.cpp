class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        
        int n = nums.size();
        int i=0;
        int j=1;
        
        while(i<n and j<n)
        {
            if(nums[i] % 2 == 0)
            {
                 i = i+2;
            }
            
            else if(nums[j] % 2 == 1)
            {
                j = j+2;
            }
            
            else
            {
                swap(nums[i],nums[j]);
            }
        }
            return nums;      
    }
};