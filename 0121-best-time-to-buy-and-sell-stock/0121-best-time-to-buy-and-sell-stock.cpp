class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int db;
        int maximumProfit=0,profit=0;
        int n=prices.size();
        for(int i=1;i<n;++i)
        {
            db=prices[i]-prices[i-1];
            profit+=db;
            
            if(profit<=0)
            {
                profit=0;
            }
            else
            {
                if(profit>maximumProfit)
                {
                    maximumProfit=profit;
                }
            }
        }
        return maximumProfit;
    }
};