class Solution {
public:
    bool isVowel(char c)
    {
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }
    long long countOfSubstrings(string word,int k) {
        int n=word.size();
        long long ans=0;
        int consonants=0,left=0;
        unordered_map<char,int> mp;
        for(int right=0;right<n;++right)
        {
            if(isVowel(word[right]))mp[word[right]]++;
            else consonants++;

            while(mp.size()==5 && consonants>=k)
            {
                ans+=n-right;
                if(isVowel(word[left]))
                {
                    mp[word[left]]--;
                    if(mp[word[left]]==0)mp.erase(word[left]);
                }
                else consonants--;
                left++;
            }
        }
        long long ans1=0;
        consonants=0,left=0;
        mp.clear();
        for(int right=0;right<n;++right)
        {
            if(isVowel(word[right]))mp[word[right]]++;
            else consonants++;
            while(mp.size()==5 && consonants>=k+1)
            {
                ans1+=n-right;
                if(isVowel(word[left]))
                {
                    mp[word[left]]--;
                    if(mp[word[left]]==0)mp.erase(word[left]);
                }
                else consonants--;
                left++;
            }
        }
        return ans-ans1;
    }
};