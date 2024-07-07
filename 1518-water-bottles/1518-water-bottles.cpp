class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ret=numBottles;
        int cans=numBottles;
        while(cans/numExchange>0)
        {
            int filled=cans/numExchange;
            ret+=filled;
            cans%=numExchange;
            cans+=filled;
        }
        return ret;
    }
};