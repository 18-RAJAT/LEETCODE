class Solution {
public:
    bool closeStrings(string word1, string word2) {
       int n=word1.size();
       int m=word2.size();
        if(n!=m)
        {
            return false;
        }
        int a[26];memset(a,0,sizeof(a));
        int b[26];memset(b,0,sizeof(b));
        for(int i=0;i<n;i++)
        {
            a[word1[i]-'a']++;
            b[word2[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if((a[i]==0 and b[i]!=0) or (a[i]!=0 and b[i]==0))
            {
                return false;
            }
        }
        sort(a,a+26);
        sort(b,b+26);
        for(int i=0;i<26;i++)
        {
            if(a[i]!=b[i])
            {
                return false;
            }
        }
        return true;
    }
};