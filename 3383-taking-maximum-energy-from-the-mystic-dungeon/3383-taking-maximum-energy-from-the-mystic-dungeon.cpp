class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        vector<int>dp(n,0);
        int ans=INT_MIN;
        for(int i=n-1;~i;--i)
        {
            if(i+k<n)
            {
                dp[i]=energy[i]+dp[i+k];
            }
            else
            {
                dp[i]=energy[i];
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};