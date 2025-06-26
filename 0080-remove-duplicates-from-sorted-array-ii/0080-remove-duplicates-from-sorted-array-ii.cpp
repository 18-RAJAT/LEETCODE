class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        for(auto& it:nums)
        {
            if(i<2 || nums[i-2]<it)
            {
                nums[i]=it,i++;
            }
        }
        return i;
    }
};