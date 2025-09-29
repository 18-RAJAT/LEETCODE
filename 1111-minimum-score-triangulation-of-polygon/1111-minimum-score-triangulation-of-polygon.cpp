class Solution {
public:
    int recur(vector<int>& ar,int i,int j,vector<vector<int>>& dp)
    {
        if(j-i==1)return 0;
        if(~dp[i][j])return dp[i][j];
        int ans=INT_MAX;
        for(int k=i+1;k<=j-1;++k)
        {
            ans=min(ans,ar[i]*ar[j]*ar[k]+recur(ar,i,k,dp)+recur(ar,k,j,dp));
        }
        dp[i][j]=ans;
        return dp[i][j];
    }
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return recur(values,0,n-1,dp);
    }
};