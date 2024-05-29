class Solution {
public:
    int numSteps(string s) {
        int ans=0;
        reverse(s.begin(),s.end());
        while(s.size()>1)
        {
            ans++;
            if(s[0]=='1')
            {
                int f=1;
                for(int i=0;i<s.size();++i)
                {
                    if(s[i]=='1')
                    {
                        s[i]='0';
                    }
                    else
                    {
                        f=0;
                        s[i]='1';
                    }
                    if(f==0)
                    {
                        break;
                    }
                }
                if(f==1)
                {
                    s.push_back('1');
                }
            }
            else
            {
                for(int i=0;i<s.size()-1;++i)
                {
                    s[i]=s[i+1];
                }
                s.pop_back();
            }
        }
        return ans;
    }
};