class Solution {
public:
    char find(char c,vector<char>&parent)
    {
        int res=0;
        if(parent[c-'a']==c)
        {
            return c;
        }
        res=parent[c-'a']=find(parent[c-'a'],parent);
        return res;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<char>parent(26);
        for(int i=0;i<26;i++)
        {
            parent[i]=i+'a';
        }
        for(int i=0;i<s1.size();i++)
        {
            char p1=find(s1[i],parent);
            char p2=find(s2[i],parent);
            parent[p1-'a']=min(p1,p2);
            parent[p2-'a']=min(p1,p2);
        }
        int m=baseStr.size();
        for(int i=0;i<m;i++)
        {
            baseStr[i]=find(baseStr[i],parent);
        }
        return baseStr;      
    }
};