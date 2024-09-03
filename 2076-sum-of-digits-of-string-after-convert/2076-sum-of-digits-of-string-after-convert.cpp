class Solution {
public:
    int getLucky(string s, int k) {
        int n=s.length();
        string str="";
        for(int i=0;i<n;++i)
        {
            int ch=s[i]-96;
            str+=to_string(ch);
        }
        int ans;
        while(k--)
        {
            ans=0;
            for(int i=0;i<str.length();++i)
            {
                ans+=(str[i]-'0');
            }
            str=to_string(ans);
        }
        return ans;
    }
};