class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size(),ans=0;
        for(int i=0;i<(1<<n);++i)
        {
            int subsets=0;
            for(int j=0;j<n;++j)
            {
                if((i&(1<<j))>=1)subsets^=nums[j];
            }
            ans+=subsets;
        }
        return ans;
    }
};