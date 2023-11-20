class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        // https://codeforces.com/contest/1898/submission/233445630
        long long n=nums.size();
        long long last=nums[n-1];
        long long ans=0;
        for(long long i=n-2;i>=0;--i)
        {
            if(nums[i]<=last)
            {
                last=nums[i];
                continue;
            }
            if(nums[i]%last==0)
            {
                ans+=nums[i]/last-1;
                // last=v[i]/last;
                continue;
            }
            ans+=nums[i]/last;
            last=nums[i]/(1+nums[i]/last);
        }
        return ans;
    }
};