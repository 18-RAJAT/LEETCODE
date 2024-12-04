class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n=str1.size(),m=str2.size();
        if(n<m)return false;
        int j=0;
        for(int i=0;i<n && j<m;i++)
        {
            if(str1[i]==str2[j])j++;
            else if((str1[i]-'a'+1)%26+'a'==str2[j]) j++;
        }
        return m==j?true:false;
    }
};