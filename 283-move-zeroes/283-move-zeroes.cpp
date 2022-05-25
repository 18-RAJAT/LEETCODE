class Solution {
public:
    void moveZeroes(vector<int>& nums) {
            
            //2pointer
          int right=0,left=0,store;
            int n=nums.size();
            while(right<n)
            {
                    if(nums[right]==0){right++;}
                    else
                    {
                            cout<<"Stdout";
                            store=nums[right];
                            nums[right]=nums[left];
                            nums[left]=store;
                            right++;left++;
                    }
            }
         
    }
};