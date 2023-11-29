class Solution {
public:
    int recur(vector<int>& coins,int amount,int idx,vector<vector<int>>& dp)
    {
        int n=coins.size();
        //base case
        if(amount==0)
        {
            return 0;
        }
        if(idx==n)
        {
            return 1e9;
        }
        int &state=dp[idx][amount];
        if(~state)
        {
            return state;
        }
        int ans=1e9;
        if(coins[idx]<=amount)
        {
            ans=min(ans,1+recur(coins,amount-coins[idx],idx,dp));//take dp
        }
        ans=min(ans,recur(coins,amount,idx+1,dp));//not take dp
        return state=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=recur(coins,amount,0,dp);
        if(ans==1e9)
        {
            return -1;
        }
        else
        {
            return ans;
        }
    }
};