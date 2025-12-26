class Solution {
public:
    int bestClosingTime(string s) {
        int n=s.size(),count=0,ans=n;
        for(int i=n-1;~i;--i)
        {
            count+=(s[i]=='Y')-(s[i]=='N');
            if(count<=0)ans=i;
            if(count<0)count=0;
        }
        return ans;
    }
};