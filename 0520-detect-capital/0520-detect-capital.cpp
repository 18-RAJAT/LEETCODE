class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.size();
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(word[i]>='A' and word[i]<='Z')
                c++;
        }
        if(c==n or c==0)
            return true;
        else if(c==1 and word[0]>='A' and word[0]<='Z')
            return true;
        else
            return false;
    }
};