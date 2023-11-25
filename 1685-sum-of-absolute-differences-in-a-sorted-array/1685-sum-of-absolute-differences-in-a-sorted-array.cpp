class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        int sum=0;
        for(int i=0;i<n;++i)
        {
            sum+=nums[i];
        }
        int left=0;
        for(int i=0;i<n;++i)
        {
            ans[i]=nums[i]*i-left+(sum-left-nums[i])-(n-i-1)*nums[i];//for each i, we need to find the sum of all the elements to the left of i and to the right of i
            left+=nums[i];
        }
        return ans;
    }
};