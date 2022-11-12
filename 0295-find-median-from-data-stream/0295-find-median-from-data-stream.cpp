class MedianFinder {
    
    priority_queue<int> max; //max heap for first half
    priority_queue<int, vector<int>, greater<int>> min; //min heap for next half
public:
    MedianFinder() {
     
        
    }
    
    void addNum(int num) {
        max.push(num);
        min.push(max.top());
        max.pop();
        if(min.size() > max.size())
        {    
            max.push(min.top());
            min.pop();
        }
    }
    
    double findMedian() {
        if(max.size() > min.size())
            return max.top();
        else
            return (max.top()+min.top())/2.0;
    }
};


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */