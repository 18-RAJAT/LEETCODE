class MedianFinder {
private:priority_queue<int> que1;
        priority_queue<int, vector<int>, greater<int> > que2;
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        if(que1.empty() &&que2.empty()) {que1.push(num);return;}
        double mid=findMedian();
        if(num<mid) {que1.push(num);
            if(que1.size()-que2.size()>1){
               int t=que1.top();
               que1.pop();
               que2.push(t);
            }
        }else{
            que2.push(num);
            if(que2.size()-que1.size()>=1){
               int t=que2.top();
               que2.pop();
               que1.push(t);
            }
        }
        return;
        
    }

    // Returns the median of current data stream
    double findMedian() {
        if(que1.empty() &&que2.empty()) return 0;
        if(que1.size()==que2.size()){
            double m=que1.top(),n=que2.top();
            return (m+n)/2;
        }
        if(que1.size()>que2.size()) return (double)que1.top();
        else return (double)que2.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */