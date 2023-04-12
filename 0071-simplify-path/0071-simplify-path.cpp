class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        string ans="",tmp="";
        int n=path.size();
        for(int i=0;i<n;++i)
        {
            if(path[i]=='/')
            {
                if(tmp=="..")
                {
                    if(not st.empty())
                    {
                        st.pop();
                    }
                }
                else if(tmp!="" and tmp!=".")
                {
                    st.push(tmp);
                }
                tmp="";
            }
            else
            {
                tmp+=path[i];
            }
        }
        if(tmp=="..")
        {
            if(not st.empty())
            {
                st.pop();
            }
        }
        else if(tmp!="" and tmp!=".")
        {
            st.push(tmp);
        }
        while(not st.empty())
        {
            auto db=st.top();
            ans="/"+db+ans;
            st.pop();
        }
        if(ans=="")
        {
            ans="/";
        }
        return ans;
    }
};