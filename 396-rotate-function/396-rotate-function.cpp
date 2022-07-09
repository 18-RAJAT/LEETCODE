class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        int Tsum=0,c=0;
        for(int i=0;i<n;++i)
        {
            Tsum=Tsum+nums[i];c=c+nums[i]*i;
        }
             int result=c;
           for(int i=n-1;i>=1;--i)
            {
               c=c+Tsum-(n*nums[i]);
               result=max(result,c);
            }
        return result;
    }
};