class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>res(n,0);
        stack<int>stk;
        
        for(int i=0;i<n;++i)
        {
            while(!stk.empty() and temperatures[i]>temperatures[stk.top()])
            {
                res[stk.top()]=abs(i-stk.top());
                stk.pop();
            }
            stk.push(i);
        }
        return res;      
    }
};