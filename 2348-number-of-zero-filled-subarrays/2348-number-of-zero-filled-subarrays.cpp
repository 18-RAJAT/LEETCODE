class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long nonZero=-1,ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                nonZero=i;
            }
            ans+=i-nonZero;
        }
        return ans;
    }
};