class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n=nums.size();
        int temp=nums[0],bit=pow(2,maximumBit)-1;
        vector<int>ans(n);
        for(int i=1;i<n;++i)temp^=nums[i];
        for(int i=0;i<n;++i)
        {
           ans[i]=temp^bit;
           temp^=nums[n-i-1];
        }
        return ans;
    }
};