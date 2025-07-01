class Solution {
public:
    int possibleStringCount(string word) {
        int n=word.size(),ans=1;
        for(int i=1;i<n;++i)
        {
            if(word[i]==word[i-1])ans++;
        }
        return ans;
    }
};