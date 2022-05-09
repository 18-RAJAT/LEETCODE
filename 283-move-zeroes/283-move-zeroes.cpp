class Solution {
public:
    void moveZeroes(vector<int>& nums) {
            
            //2pointer
            int right=0,left=0,temp;
            int n = nums.size();
            
            while(right < n)
            {
                   if(nums[right]==0)
                   {
                           right++;
                   }
                    else
                    {
                            temp=nums[left];
                            nums[left]=nums[right];
                            nums[right]=temp;
                            
                            right++;left++;
                    }
            }
        
    }
};