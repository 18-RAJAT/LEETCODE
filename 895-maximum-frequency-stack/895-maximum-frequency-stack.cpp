class FreqStack {
    
        priority_queue<vector<int>>pq;
        unordered_map<int,int>mp;
            
          int id = 0;
    
public:
      FreqStack() {
        
    }
    
    void push(int val) {
        
        ++mp[val];
        pq.push({mp[val],id++,val});
        
    }
    
    int pop() {
        
        auto p = pq.top();
        pq.pop();
        
        --mp[p[2]];
        
        return p[2];
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */