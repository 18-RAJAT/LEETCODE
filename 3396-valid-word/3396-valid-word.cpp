class Solution {
public:
    bool isValid(string word) {
        int n=word.size();
        if(n<3)
        {
            return false;
        }
        bool vowel=false,consonant=false;
        unordered_set<char>us={'a','e','i','o','u','A','E','I','O','U'};
        for(int i=0;i<n;++i)
        {
            if(isalpha(word[i]))
            {
                vowel|=!us.count(word[i]);
                consonant|=us.count(word[i]);
            }
            else if(isdigit(word[i]))
            {
                
            }
            else
            {
                return false;
            }
        }
        return vowel && consonant;
    }
};