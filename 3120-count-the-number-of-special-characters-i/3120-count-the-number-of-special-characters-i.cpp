class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>lower(26,0),upper(26,0);
        for(auto& it:word)
        {
            if(it>='a' && it<='z')
            {
                lower[it-'a']++;
            }
            else
            {
                upper[it-'A']++;
            }
        }
        int ans=0;
        for(int i=0;i<26;++i)
        {
            if(lower[i]>=1 && upper[i]>=1)
            {
                ans++;
            }
        }
        return ans;
    }
};