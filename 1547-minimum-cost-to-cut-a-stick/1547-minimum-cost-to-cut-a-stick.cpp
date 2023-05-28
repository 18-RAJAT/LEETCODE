class Solution {
public:
    int minCost(int n,vector<int>& c) {
        //sort the cut values
        sort(c.begin(),c.end());
        int len=c.size();
        vector<vector<int>> dp(len,vector<int>(len,-1));
        
        dfs(c,0,len-1,0,n,dp);
        return dp[0][len-1];
    }
    int dfs(vector<int>& c,int startInd,int endInd,int startVal,int endVal,vector<vector<int>>& dp)
    {
        if(startInd>endInd)
            return 0;
        if(dp[startInd][endInd]!=-1)
            return dp[startInd][endInd];
        
        int ans=INT_MAX;
        int currLen=endVal-startVal;
        for(int i=startInd;i<=endInd;i++)
        {
            ans=min<int>(ans,currLen+dfs(c,startInd,i-1,startVal,c[i],dp)+dfs(c,i+1,endInd,c[i],endVal,dp));
        }
        dp[startInd][endInd]=ans;
        return dp[startInd][endInd];
    }
};