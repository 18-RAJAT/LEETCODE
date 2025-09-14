class Solution {
public:
    bool isVowel(char ch)
    {
        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        set<string>st;
        map<string,int>cap,vowel;
        for(auto& it: wordlist)st.insert(it);
        for(int i=wordlist.size()-1;~i;--i)
        {
            string str=wordlist[i];
            transform(str.begin(),str.end(),str.begin(),::tolower);
            cap[str]=i;
            for(int j=0;j<str.size();++j)
            {
                if(isVowel(str[j]))
                {
                    str[j]='*';
                }
            }
            vowel[str]=i;
        }
        vector<string>ans;
        for(auto& it:queries)
        {
            string s=it;
            transform(s.begin(),s.end(),s.begin(),::tolower);
            string t=s;
            for(int i=0;i<s.size();++i)
            {
                if(isVowel(s[i]))s[i]='*';
            }
            if(st.find(it)!=st.end())
            {
                ans.push_back(it);
            }
            else if(cap.find(t)!=cap.end())
            {
                ans.push_back(wordlist[cap[t]]);
            }
            else if(vowel.find(s)!=vowel.end())
            {
                ans.push_back(wordlist[vowel[s]]);
            }
            else 
            {
                ans.push_back("");
            }
        }
        return ans;
    }
};