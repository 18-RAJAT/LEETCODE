class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int> (2,-1));
        return f(0,1,prices,dp);

    }
    int f(int i,int b,vector<int>& prices,vector<vector<int>> &dp){
        if(i >= prices.size()){
            return 0;
        }
        if(dp[i][b]!=-1){
            return dp[i][b];
        }
        int profit = 0;
        if(b){
            profit = max(-prices[i] + f(i+1,0,prices,dp),f(i+1,1,prices,dp));
        }else{
            profit = max(prices[i] + f(i+2,1,prices,dp),f(i+1,0,prices,dp));
        }
        return dp[i][b] = profit;
    }
};