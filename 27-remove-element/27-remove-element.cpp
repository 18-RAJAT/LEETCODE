class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
            int temp=0;
            for(int i=0;i<nums.size();++i)
            {
                  if(nums[i]!=val){swap(nums[i],nums[temp]);temp=temp+1;}
            }
            return temp;
    }
};























