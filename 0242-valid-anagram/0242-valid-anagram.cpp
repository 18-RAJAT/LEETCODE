class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>freq(26,0);
        if(s.length()!=t.length())
        {
            return false;
        }
        //store freq of char's in s1 and s2
        for(int i=0;i<s.length();++i)
        {
            freq[s[i]-'a']++;
            freq[t[i]-'a']--;
        }
        //checking if freq of every char's is 0
        for(int i=0;i<26;++i)
        {
            if(freq[i]!=0)
            {
                return false;
            }
        }
        return true;
    }
};