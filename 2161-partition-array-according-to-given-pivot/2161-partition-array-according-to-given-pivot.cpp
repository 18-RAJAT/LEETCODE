class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int>ans(n);
        int cnt=0;
        for(int i=0;i<n;++i)
        {
            if(nums[i]<pivot)ans[cnt++]=nums[i];
        }
        for(int i=0;i<n;++i)
        {
            if(nums[i]==pivot)ans[cnt++]=nums[i];
        }
        for(int i=0;i<n;++i)
        {
            if(nums[i]>pivot)ans[cnt++]=nums[i];
        }
        return ans;
    }
};