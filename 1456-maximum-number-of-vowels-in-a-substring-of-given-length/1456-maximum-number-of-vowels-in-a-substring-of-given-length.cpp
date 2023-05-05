class Solution {
public:
    int maxVowels(string s, int k) {
        auto isVowel=[&](char ch)->bool
        {
            if(ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u')
            {
                return true;
            }
            return false;
        };
        int maximumVowel=0;
        int currentPosVowel=0;
        for(int i=0;i<s.size();++i)
        {
            currentPosVowel+=isVowel(s[i]);
            
            if(k<=i)
            {
                currentPosVowel-=isVowel(s[i-k]);
            }
             maximumVowel=max<int>(maximumVowel,currentPosVowel);
        }
        return maximumVowel;
    }
};