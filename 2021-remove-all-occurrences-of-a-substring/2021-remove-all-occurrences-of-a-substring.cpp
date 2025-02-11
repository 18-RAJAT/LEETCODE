class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n=s.size(),m=part.size();
        stack<char>st;
        for(int i=0;i<n;++i)
        {
            st.push(s[i]);
            stack<char>stk;
            if(st.size()>=m)
            {
                int j=i,k=m-1;
                while(k>=0 && st.top()==part[k])
                {
                    stk.push(st.top());
                    st.pop();              
                    k--;
                }
                if(stk.size()!=m)
                {
                    while(!stk.empty())
                    {
                        st.push(stk.top());
                        stk.pop();
                    }
                }
            }
        }     
        string ans="";
        while(!st.empty())
        {
            ans.push_back(st.top()),st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};