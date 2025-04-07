class Solution {
public:
    bool canPartition(vector<int>& a) {
        int sum=accumulate(a.begin(),a.end(),0LL);
        if(sum%2!=0)return false;
        int k=sum/2;
        vector<int>dp(k+1,0);
        dp[0]=1;
        for(auto& it:a)
        {
            for(int j=k;j>=it;--j)
            {
                dp[j]=dp[j]||dp[j-it];
            }
        }
        return dp[k];
    }
};