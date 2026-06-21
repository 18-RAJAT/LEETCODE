class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int max_bars=0;
        for(auto& it:costs)
        {
            if(it<=coins)
            {
                max_bars++;
                coins-=it;
            }
        }
        return max_bars;
    }
};