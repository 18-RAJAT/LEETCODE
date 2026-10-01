class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        unordered_map<char,char>ump;
        ump['(']=')';
        ump['{']='}';
        ump['[']=']';
        for(auto& chars:s)
        {
            if(chars=='(' || chars=='[' || chars=='{')
            {
                st.push(chars);
            }
            else
            {
                if(st.empty())
                {
                    return false;
                }
                else if(ump[st.top()]!=chars)
                {
                    return false;
                }
                else
                {
                    st.pop();
                }
            }
        }
        return st.empty()?true:false;
    }
};