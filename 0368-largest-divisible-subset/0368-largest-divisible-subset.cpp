class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
        {
            return {};
        }
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        vector<int>parent(n,-1);
        int maxIndex=0;
        for(int i=1;i<n;++i)
        {
            for(int j=0;j<i;++j)
            {
                if(nums[i]%nums[j]==0)
                {
                    if(dp[i]<dp[j]+1)
                    {
                        dp[i]=dp[j]+1;
                        parent[i]=j;
                    }
                }
            }
            //finding the index of the largest divisible subset
            if(dp[i]>dp[maxIndex])
            {
                maxIndex=i;
            }
        }
        vector<int>res;
        //for printing the subset of the largest divisible subset
        while(~maxIndex)
        {
            res.push_back(nums[maxIndex]);
            maxIndex=parent[maxIndex];
        }
        return res;
    }
};