class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        int negative=1,positive=0;
        vector<int>ans(n,0);
        for(int i=0;i<n;++i)
        {
            if(nums[i]<0)
            {
                ans[negative]=nums[i];
                negative+=2;
            }
            else
            {
                ans[positive]=nums[i];
                positive+=2;
            }
        }
        return ans;
    }
};