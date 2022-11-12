class MedianFinder {
public:
    // we will use heaps (min and max) to get the median using . We will try to keep them balanced on basis of their size so that at    end we will have the medians at top.
    // we are not interested in other numbers just the middle one thats why using heap combo of min and max .
	// we are using min and max beacuse we will maintain our heaps in a way that max of max heap will always be lesser than equal to min of min Heap in this way we be able to get the medians
    priority_queue<int,vector<int>,greater<int>> minH;
    priority_queue<int> maxH;
    MedianFinder() {}
    
    void addNum(int num) 
    {
        if(maxH.empty() or num<maxH.top())
        {
            maxH.push(num);
        }
        else
        {
            minH.push(num);
        }
        if(maxH.size()>minH.size()+1)
        {
            minH.push(maxH.top());
            maxH.pop();
        }
        else if(minH.size()>maxH.size()+1)
        {
            maxH.push(minH.top());
            minH.pop();
        }
    }
    
    double findMedian() 
    {
        if(maxH.size()==minH.size())
        {
            return (maxH.top()+minH.top())/2.0;
        }
        else
        {
            return maxH.size()>minH.size()?maxH.top():minH.top();
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */