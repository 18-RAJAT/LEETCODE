#define ll long long
#define si set<int>

class Solution {
public:
    int countConsistentStrings(string a, vector<string>& w) {
        si st(a.begin(),a.end());
        int ct=0;
        for(int i=0;i<w.size();++i)
        {
            string s=w[i];int total=0;
            for(int i=0;i<s.size();++i)
            {if(st.count(s[i]))total++;}
            if(total==s.size()){ct++;}
        }
        return ct;
    }
};