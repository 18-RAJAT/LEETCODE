class Solution {
public:
    // 1. 3 options a day buy sell or leave
    // 2. If bought , then only sell or leave (until you sell)
    // 3. If sold , then only buy or leave (until you sell)
    // 4. If left , then buy or sell (if you have any)
    int maxProfit(vector<int>& prices) {
        int hold=INT_MIN;
        int temp=INT_MIN;
        int empty=0;
        
        int n=prices.size();
        // for(int i=1;i<n;++i)
        for(auto &i:prices)
        {
            hold=max(hold,empty-i);
            empty=max(empty,temp);
            temp=hold+i;
        }
        int maximumProfit=max(empty,temp);
        return maximumProfit;
    }
};