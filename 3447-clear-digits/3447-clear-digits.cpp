class Solution {
public:
    string clearDigits(string s) {
        string ans="";
        stack<char>st;
        for(auto& it:s)
        {
            if(isdigit(it))
            {
                if(!st.empty())
                {
                    st.pop();
                }
            }
            else
            {
                st.push(it);
            }
        }
        while(!st.empty())
        {
            ans=st.top()+ans,st.pop();
        }
        return ans;
    }
};