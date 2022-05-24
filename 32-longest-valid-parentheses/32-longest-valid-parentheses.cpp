class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>stk;
            stk.push(-1);
            int maxP=0;
            for(int i=0;i<s.size();++i)
            {
                    int temp=stk.top();
                    if(temp!=-1 and s[i]==')' and s[temp]=='(')
                    {
                            stk.pop();
                            maxP=max(maxP,i-stk.top());
                    }
                    else{stk.push(i);}
            }
            return maxP;
    }
};