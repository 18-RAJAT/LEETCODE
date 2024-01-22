class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(2);
        for(int i=0;i<n;i++)
        {
            (nums[abs(nums[i])-1]<0)?ans[0]=abs(nums[i]):nums[abs(nums[i])-1]*=-1;
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]>=1)
            {
                ans[1]=i+1;
                break;
            }
        }
        return ans;
    }
};