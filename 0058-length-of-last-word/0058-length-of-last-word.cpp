class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int len=0;
        for(int i=n-1;~i;--i)
        {
            if(s[i]!=' ')
            {
                len++;
            }
            else if(len>=1)
            {
                return len;
            }
        }
        return len;
    }
};