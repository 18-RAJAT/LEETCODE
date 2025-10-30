class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n=target.size();
        vector<int>dp(n,0);
        int tmp=target[0];
        dp[0]=target[0];
        for(int i=1;i<n;++i)
        {
            if(target[i]<=target[i-1])dp[i]=dp[i-1];
            else dp[i]=dp[i-1]+(target[i]-target[i-1]);
        }
        return dp[n-1];
    }
};