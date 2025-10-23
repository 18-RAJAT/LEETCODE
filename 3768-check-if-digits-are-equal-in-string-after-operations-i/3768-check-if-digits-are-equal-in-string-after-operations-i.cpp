class Solution {
public:
    bool hasSameDigits(string s) {
        int n=s.size();
        while(n>2)
        {
            string s1="";
            for(int i=0;i<n-1;++i)
            {
                int x=((s[i]-'0')+(s[i+1]-'0'))%10;
                s1+=('0'+x);
            }
            s=s1;
            n=s.size();
        }
        return s[0]==s[1];
    }
};