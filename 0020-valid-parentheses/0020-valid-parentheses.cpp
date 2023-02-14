class Solution {
public:
    bool isValid(string s) {
        function<bool(char,char)>Pairs=[](char a,char b)
        {
            return (a=='(' and b==')') or (a=='[' and b==']') or (a=='{' and b=='}');
        };
        std:stack<char>st;
        for (char c:s) 
        {
            if (c == '(' or c == '{' or c == '[') 
            {
                st.push(c);
            } 
            else 
            {
                if (st.empty() or not Pairs(st.top(),c)) 
                {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};