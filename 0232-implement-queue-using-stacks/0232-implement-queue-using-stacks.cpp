class MyQueue {
public:
    
    stack<int>s;
    stack<int>q;
    MyQueue() {
        
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        if(q.empty())
        {
            while(!s.empty())
            {
                q.push(s.top());
                s.pop();
            }
        }
        
        int ans=q.top();
        q.pop();
        return ans;
    }
    
    int peek() {
        if(q.empty())
        {
            while(!s.empty())
            {
                q.push(s.top());s.pop();
              
            }
        }
        return q.top();
    }
    
    bool empty() {
        if(s.empty()) return q.empty();
        return false;
    }
};
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */