class Solution {
public:
    bool isValid(string s) {
        
        function<bool(char,char)>pairs=[&](char a,char b)->bool
        {
            if(a=='(' and b==')')return true;
            if(a=='{' and b=='}')return true;
            if(a=='[' and b==']')return true;
            return false;
        };
        
        stack<char>st;
        for(auto& it:s)
        {
            if(it=='(' or it=='{' or it=='[')
            {
                st.push(it);
            }
            else
            {
                if(st.empty())return false;
                if(pairs(st.top(),it))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if(st.empty())
        {
            return true;
        }
        return false;
    }
};