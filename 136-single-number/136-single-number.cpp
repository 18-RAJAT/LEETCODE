class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int target=0;
            for(int i=0;i<nums.size();++i)
            {
                    target=target^nums[i];
            }
            return target;
    }
};