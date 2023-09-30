class Solution {
public:
    char lower_case(char c)
    {
        if((c>='a' && c<='z') || (c>='0' && c<='9'))
        {
            return c;
        }
        else
        {
            return c-'A'+'a';//A=65,a=97
        }
    }
    bool alpha_numeric(char c)
    {
        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9'))
        {
            return true;
        }
        return false;
    }
    bool palindrome(string s)
    {
        int start=0,end=s.size()-1;
        while(start<end)
        {
            if(lower_case(s[start])!=lower_case(s[end]))//chk
            {
                return false;
            }
            else
            {
                start++,end--;
            }
        }
        return true;
    }
    bool isPalindrome(string s) {
        string ans="";
        int n=s.size();
        for(int i=0;i<n;++i)
        {
            if(alpha_numeric(s[i]))
            {
                ans+=s[i];
            }
        }
        return palindrome(ans)?true:false;
    }
};