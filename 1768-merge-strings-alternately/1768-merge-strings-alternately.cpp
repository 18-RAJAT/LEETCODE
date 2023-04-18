class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        auto mergeBothString=[&](string word1,string word2)->auto
        {
            string possible="";
            int pointer1=0;
            int pointer2=0;
            
            while(pointer1<word1.size() and pointer2<word2.size())
            {
                possible+=word1[pointer1];
                possible+=word2[pointer2];
                pointer1++;pointer2++;
            }
            while(pointer1<word1.size())
            {
                possible+=word1[pointer1];pointer1++;
            }
            while(pointer2<word2.size())
            {
                possible+=word2[pointer2];pointer2++;
            }
            return possible;
        };
        return mergeBothString(word1,word2);
    }
};