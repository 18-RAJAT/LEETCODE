class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long n=nums.size();
        vector<vector<int>>solution(n);
        vector<int>dp;
        
        for(long long i=0;i<n;++i)
        {
            for(long long j=0;j<i;++j)
            {
                if(nums[i]%nums[j]==0 and solution[j].size()>solution[i].size())
                {
                    solution[i]=solution[j];
                }
            }
            solution[i].push_back(nums[i]);
            if(dp.size()<solution[i].size())
            dp=solution[i];
        }
        return dp;
    }
};