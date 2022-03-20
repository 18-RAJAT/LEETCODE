class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int first = 0;
        int mid = 0;
        int last = nums.size()-1;
        
        while(mid <= last)
        {
            //Using Switch cases...!!
            switch(nums[mid])
            {
                case 0: swap(nums[first++] , nums[mid++]);
                    break;
                    
                case 1: mid++;
                    break;
                    
                case 2: swap(nums[mid],nums[last--]);
                    break;
            }
        }
    }
};