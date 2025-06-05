class Solution {
public:
    char find(char c,vector<char>& ch)
    {
        int res=0;
        if(ch[c-'a']==c)return c;
        res=ch[c-'a']=find(ch[c-'a'],ch);
        return res;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<char>ch(26);
        for(int i=0;i<26;++i)ch[i]=i+'a';
        for(int i=0;i<s1.size();++i)
        {
            char p1=find(s1[i],ch);
            char p2=find(s2[i],ch);
            ch[p1-'a']=min(p1,p2);
            ch[p2-'a']=min(p1,p2);
        }
        int n=baseStr.size();
        for(int i=0;i<n;++i)baseStr[i]=find(baseStr[i],ch);
        return baseStr;
    }
};