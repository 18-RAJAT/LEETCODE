class Solution {
public:
    const int Mod=1e9+7;
    int countPartitions(vector<int>& nums, int k) {
        int n=nums.size(),x=0;
        vector<int>dp(n+1,0),ndp(n+1,0);
        multiset<int>ms;
        dp[0]=1,ndp[0]=1;
        for(int i=1;i<=n;++i)
        {
            ms.insert(nums[i-1]);
            while(*ms.rbegin()-*ms.begin()>k)
            {
                ms.erase(ms.find(nums[x]));
                x++;
            }
            ndp[i]=(dp[i-1]-(x>0?dp[x-1]:0)+Mod)%Mod;
            dp[i]=(dp[i-1]+ndp[i])%Mod;
        }
        return ndp[n];
    }
};