class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n=temperatures.size();
        vector<int>ans(n,0);
        
        stack<int>s;
        for(int i=0;i<n;++i)
        {
            while(!s.empty() and temperatures[i]>temperatures[s.top()])
            {
                ans[s.top()]=abs(i-s.top());
                s.pop();
            }
            s.push(i);
        }
        return ans;       
    }
};