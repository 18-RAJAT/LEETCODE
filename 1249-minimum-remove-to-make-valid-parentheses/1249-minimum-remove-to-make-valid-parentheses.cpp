class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        stack<pair<char,int>>stk;
        
        for(int i=0;i<s.length();++i)
        {
            if(s[i] == '(')
            {
                stk.push({s[i],i});
            } 
            else if(!stk.empty() and stk.top().first == '(' and s[i] == ')')
            {
                stk.pop();
            }
            else if(s[i] == ')')
            {
                stk.push({s[i],i});
            }
        }
        
        while(!stk.empty())
        {
            s.erase(s.begin() + stk.top().second);
            stk.pop();
        }
        return s;
    }
};