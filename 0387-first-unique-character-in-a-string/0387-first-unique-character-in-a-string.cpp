class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.size();
        int chars[26];
        fill(chars,chars+26,0);
        for(int i=0;i<n;++i)
        {
            chars[s[i]-'a']++;
        }
        for(int i=0;i<n;++i)
        {
            //check if the character is unique or not
            if(chars[s[i]-'a']==1)
            {
                return i;
            }
        }
        return -1;
    }
};