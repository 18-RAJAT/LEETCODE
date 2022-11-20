class Solution {
public:

    int calculateUtil(string &s,int &i)
    {
        int res=0;
        int lastOp=1;
        int current=0;
        
        int n=s.size();
        while(i<n)
        {
            if(s[i]=='(')
            {
                current=calculateUtil(s,++i);
            }
            else if(s[i]==')')
            {
                break;
            }
            else if(s[i]=='+')
            {
                res+=current*lastOp;
                lastOp=1;
                current=0;
            }
            else if(s[i]=='-')
            {
                res+=current*lastOp;
                lastOp=-1;
                current=0;
            }
            else if(s[i]!=' ')
            {
                current=current*10+(s[i]-'0');
            }
            ++i;
        }
        int ans=res+=current*lastOp;
        return ans;
    }

    int calculate(string s) 
    {
        int i=0;
        return calculateUtil(s,i);
    }
};