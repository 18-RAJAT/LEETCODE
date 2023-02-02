class Solution {
public:
    bool isSorted(string& s1,string& s2,string& order)
    {
        int n=s1.length();
        int m=s2.length();
        
        int mn=min(n,m);
        for(int i=0;i<mn;++i)
        {
            int idx1=order.find(s1[i]);
            int idx2=order.find(s2[i]);
            
            if(idx1==idx2)
            {
                continue;
            }
            if(idx1<idx2)
            {
                return true;
            }
            if(idx1>idx2)
            {
                return false;
            }
        }
        return n<=m;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        map<char,int>chk;
        for(int i=0;i<26;++i)
        {
            chk[order[i]]=i;
        }
        int n=words.size();
        for(int i=1;i<n;++i)
        {
            if(not isSorted(words[i-1],words[i],order))
            {
                return false;
            }
        }
        return true;
    }
};