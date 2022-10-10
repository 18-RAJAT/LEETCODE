class Solution {
public:
    string breakPalindrome(string pali) {
        int n=pali.size();
        if(n<2)
        {
            return "";
        }
        for(int i=0;i<n/2;++i)
        {
            if(pali[i]!='a')
            {
                pali[i]='a';
                return pali;
            }
        }
        pali[n-1]='b';
        return pali;
    }
};