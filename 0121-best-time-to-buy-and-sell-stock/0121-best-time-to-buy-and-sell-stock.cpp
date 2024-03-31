class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int val=1e9,profit=0;
        for(int i=0;i<n;++i)
        {
            val=min(val,prices[i]);
            profit=max(profit,prices[i]-val);
        }
        return profit;
    }
};