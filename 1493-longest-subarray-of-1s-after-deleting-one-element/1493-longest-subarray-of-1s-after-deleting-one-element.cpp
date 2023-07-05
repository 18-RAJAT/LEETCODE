class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int start=0,end=0;
        int count=0,result=0;
        while(end<nums.size())
        {
            if(nums[end]==0)
            {
                count++;
            }
            while(count>1)
            {
                if(nums[start]==0)
                {
                    count--;
                }
                start++;
            }
            result=max<int>(result,end-start);
            end++;
        }
        return result;
    }
};