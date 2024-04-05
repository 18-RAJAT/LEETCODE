class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        for(auto& i:s)
        {
            if(st.empty())
            {
                st.push(i);
            }
            else
            {
                (abs(st.top()-i)==32)?st.pop():st.push(i);
            }
        }
        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};