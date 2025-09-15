class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        if(brokenLetters.size()==26)return 0;
        unordered_set<char>st;
        for(auto& it:brokenLetters)st.insert(it);
        int cnt=0;
        for(int i=0;i<text.size();++i)
        {
            if(st.count(text[i]))
            {
                while(i<text.size() && text[i]!=' ')i++;
            }
            else if(text[i]==' ')cnt++;
            else if(i==text.size()-1)cnt++;
        }
        return cnt;
    }
};