class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int c=0;
        string ans="";
        for(int i=0;i<(int)s.size();++i)
        {
            if(s[i]=='(')
            {
                c++;
            }
            else if(s[i]==')')
            {
                if(c==0)
                {
                    continue;
                }
                c--;
            }
            ans+=s[i];
        }
        string res="";
        for(int i=(int)ans.size()-1;~i;--i)
        {
            if(ans[i]=='(' && c>0)
            {
                c--;
                continue;
            }
            res+=ans[i];
        }
        reverse(res.begin(),res.end());
        return res;
    }
};