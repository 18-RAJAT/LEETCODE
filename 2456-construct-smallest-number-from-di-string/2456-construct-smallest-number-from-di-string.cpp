class Solution {
public:
    string smallestNumber(string p) {
        string res;
        stack<int>st;
        for(int i=0;i<=p.size();++i)
        {
            st.push(i+1);
            if(i==p.size() || p[i]=='I')
            {
                while(!st.empty())
                {
                    res+=to_string(st.top());
                    st.pop();
                }
            }
        }
        return res;
    }
};