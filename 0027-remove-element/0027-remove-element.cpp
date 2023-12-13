class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0,j=n-1;
        while(i<=j)
        {
            if(nums[i]==val)
            {
                swap(nums[i],nums[j]);
                j--;
            }
            else
            {
                i++;
            }
        }
        return j+1;//j+1 is the length of the array after removing the elements
    }
};