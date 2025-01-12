class Solution {
public:
    bool canBeValid(string s,string locked) {
        int n=s.length();
        if(n&1)return false;
        int open=0;
        for(int i=0;i<n;++i)
        {
            (s[i]=='(' || locked[i]=='0')?open++:open--;
            if(open<0)return false;
        }
        int close=0;
        for(int i=n-1;~i;--i)
        {
            (s[i]==')'||locked[i]=='0')?close++:close--;
            if(close<0)return false;
        }
        return true;
    }
};