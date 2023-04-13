class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>s;
        popped.push_back(INT_MIN);
        reverse(popped.begin(),popped.end());
        s.push(INT_MAX);
        
        for(int i=0;i<pushed.size();++i)
        {
            s.push(pushed[i]);
            while(s.top()==popped.back())
            {
                s.pop();
                popped.pop_back();
            }
        }
        return ((s.size()==1)?true:false);
    }
};