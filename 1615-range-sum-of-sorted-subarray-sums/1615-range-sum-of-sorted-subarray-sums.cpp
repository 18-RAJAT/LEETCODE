class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>ans;
        int sum=0;
        for(int i=0;i<nums.size();++i)
        {
            sum=0;
            for(int j=i;j<nums.size();++j)
            {
                sum+=(nums[j]%1000000007);
                ans.push_back(sum);
            }
        }
        sort(ans.begin(),ans.end());
        int res=0;
        for(int i=left-1;i<right;++i)res=(res%1000000007)+(ans[i])%1000000007;
        return res%1000000007;
    }
};