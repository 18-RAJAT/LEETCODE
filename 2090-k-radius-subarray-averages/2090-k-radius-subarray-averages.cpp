class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long long n=nums.size();
        long long sum=0;
        int dict=2*k+1;
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(i-dict>=0)sum-=nums[i-dict];
            if(i>=dict-1)ans[i-k]=sum/dict;
        }
        return ans;
    }
};