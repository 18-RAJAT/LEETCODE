class StockSpanner {
public:
    stack<int>prices,idx;
    int span;
    StockSpanner() {
        span=0;
    }
    
    int next(int price) {
        span=1;
        while(prices.size()!=0 and prices.top()<=price)
        {
            span+=idx.top();
            prices.pop();
            idx.pop();
        }
        prices.push(price);
        idx.push(span);
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */