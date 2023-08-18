class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m=0;
        for(auto&it:t)
        {
            if(s[m]==it)
            {
                m++;
            }
        }
        return (m==s.size())?true:false;
    }
};