class Solution {
public:
    
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>s;
        int i=0,n = pushed.size();
        
        for(auto p : pushed)
        {
            s.push(p);
            
            while(!s.empty() and s.top() == popped[i])
            {
                s.pop();
                i++;
            }
        }
        
        return i == n;
        
    }
};