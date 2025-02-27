class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size(),ans=0;
        unordered_map<int,int>idx;
        vector<vector<int>>dp(n,vector<int>(n,2));
        for(int i=0;i<n;++i)idx[arr[i]]=i;
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                int x=arr[j]-arr[i];
                if(x<arr[i] && idx.count(x))
                {
                    int k=idx[x];
                    dp[i][j]=dp[k][i]+1;
                    ans=max(ans,dp[i][j]);
                }
            }
        }
        return ans>2?ans:0;
    }
};