class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<n;++i)
        {
            if(i>=1 && nums[i]==nums[i-1])continue;
            int j=i+1,k=n-1;
            while(j<k)
            {
                if(nums[i]+nums[j]+nums[k]==0)
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    int prevJ=nums[j],prevK=nums[k];
                    while(j<k && nums[j]==prevJ)j++;
                    while(j<k && nums[k]==prevK)k--;
                }
                else if(nums[i]+nums[j]+nums[k]<0)j++;
                else k--;
            }
        }
        return ans;
    }
};