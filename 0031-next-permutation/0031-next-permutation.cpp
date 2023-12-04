class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        for(int i=n-2;i>=0;--i)
        {
            if(nums[i]<nums[i+1])//find the first element from the last which is smaller than its next element
            {
                int j=n-1;//start from the last
                while(j>i && nums[j]<=nums[i])//find the first element from the last which is greater than nums[i]
                {
                    j--;
                }
                swap(nums[i],nums[j]);
                reverse(nums.begin()+i+1,nums.end());//reverse the array from i+1 to the end
                return;
            }
        }
        reverse(nums.begin(),nums.end());//if no such element found then reverse the whole array
    }
};