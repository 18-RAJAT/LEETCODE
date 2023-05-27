class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        //bottom up
        int n=stoneValue.size();
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        
        int i=n-1;
        while(i>=0)
        {
            int ans=INT_MIN;
            ans=max<int>(ans,stoneValue[i]-dp[i+1]);
            if(i+1<stoneValue.size())
            {
                ans=max<int>(ans,stoneValue[i]+stoneValue[i+1]-dp[i+2]);
            }
            if(i+2<stoneValue.size())
            {
                ans=max<int>(ans,stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-dp[i+3]);
            }
            dp[i]=ans;i--;
        }
        if(dp[0]==0)
        {
            return "Tie";
        }
        return dp[0]<0?"Bob":"Alice";
    }
};