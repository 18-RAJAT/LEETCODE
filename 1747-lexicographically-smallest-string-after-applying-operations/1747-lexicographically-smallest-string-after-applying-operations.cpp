class Solution {
public:
    string add(string s,int x)
    {
        for(int i=1;i<s.size();i+=2)s[i]=(s[i]-'0'+x)%10+'0';
        return s;
    }
    string check(string s,int x)
    {
        int n=s.size();
        x=x%n;
        return s.substr(n-x)+s.substr(0,n-x);
    }
    string findLexSmallestString(string s, int a, int b) {
        string ans=s;
        queue<string>q;
        unordered_set<string>st;
        q.push(s);
        while(q.size())
        {
            auto tmp=q.front();
            ans=min(ans,tmp);
            q.pop();
            auto F=add(tmp,a),S=check(tmp,b);
            if(st.find(F)==st.end())
            {
                q.push(F);
                st.insert(F);
            }
            if(st.find(S)==st.end())
            {
                q.push(S);
                st.insert(S);
            }
        }
        return ans;
    }
};