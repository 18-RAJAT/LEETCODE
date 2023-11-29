class MinStack {
public:
    stack<int>stk,minimum;
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        if(minimum.empty() || val<minimum.top())
        {
            minimum.push(val);
        }
        else
        {
            minimum.push(minimum.top());
        }
    }
    
    void pop() {
        stk.pop();
        minimum.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minimum.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */