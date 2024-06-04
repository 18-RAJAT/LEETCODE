class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.size();
        int a[26];
        memset(a,0,sizeof(a));
        int b[26];
        memset(b,0,sizeof(b));
        
        auto convert=[&](int i)->void
        {
            if(s[i]>='a' && s[i]<='z')
            {
                a[s[i]-'a']++;
            }
            else
            {
                b[s[i]-'A']++;
            }
        };
        
        for(int i=0;i<n;++i)
        {
            convert(i);
        }
        long long int ans=0;
        bool check=false;
        for(int i=0;i<26;++i)
        {
            if(a[i]&1)
            {
                check=true;
            }
            ans+=a[i]/2;
        }
        for(int i=0;i<26;++i)
        {
            if(b[i]&1)
            {
                check=true;
            }
            ans+=b[i]/2;
        }
        return (check)?2*ans+1:2*ans;
    }
};