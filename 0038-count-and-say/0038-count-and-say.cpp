class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
        {
            return "1";
        }
        auto s=countAndSay(n-1);
        string ans="";
        int x=s.size();
        if(x==1)
        {
            ans+="1";
            ans+=s[0];
        }
        if(x>1)
        {
            for(int i=0;i<x;++i)
            {
                int ct=1;
                while(i<x-1 and s[i]==s[i+1])
                {
                    ct++;i++;
                }
                ans+=('0'+ct);
                ans+=s[i];
            }
        }
        return ans;
    }
};