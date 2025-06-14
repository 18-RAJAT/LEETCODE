class Solution {
public:
    int minMaxDifference(int num) {
        string s1=to_string(num),s2=to_string(num);
        int mx,mn;
        mx=mn=0;
        char ch1=s1[0],ch2=s1[0];
        for(int i=0;i<s1.size();++i)
        {
            if(s1[i]!='9')
            {
                ch1=s1[i];
                break;
            }
        }
        for(int i=0;i<s1.size();++i)
        {
            if(s1[i]==ch1)
            {
                s1[i]='9';
            }
        }
        for(int i=0;i<s2.size();++i)
        {
            if(s2[i]==ch2)
            {
                s2[i]='0';
            }
        }
        int n1=0,n2=0; 
        for(int i=0;i<s1.size();++i)
        {
            n1=n1*10+(s1[i]-'0');
            n2=n2*10+(s2[i]-'0');
        }
        return abs(n1-n2);
    }
};