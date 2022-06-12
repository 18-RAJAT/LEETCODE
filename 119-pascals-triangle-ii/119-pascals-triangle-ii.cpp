class Solution {
public:
    vector<int> getRow(int rowIdx) {
        vector<int>dp(rowIdx+1);
        {
                dp[0]=1;
                for(int i=0;i<=rowIdx;++i)
                {
                        for(int j=i;j>0;--j){dp[j]+=dp[j-1];}
                }
        }
            return dp;
    }
};