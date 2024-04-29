class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int x_sum=0;
        for(int i=0;i<n;++i)
        {
            x_sum^=nums[i];
        }
        int ans=0;
        k^=x_sum;
        while(k>=1)
        {
            ans+=k&1;
            k>>=1;
        }
        return ans;
    }
};