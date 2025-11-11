class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[101][101]{0};
        for(auto& i:strs)
        {
            int zeros=0,ones=0;
            for(auto& it:i)it=='0'?zeros++:ones++;
            for(int i=m;i>=zeros;--i)
            for(int j=n;j>=ones;--j)
            dp[i][j]=max(dp[i][j],dp[i-zeros][j-ones]+1);
        }
        return dp[m][n];
    }
};