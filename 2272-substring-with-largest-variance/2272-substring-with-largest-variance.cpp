class Solution {
public:
    int largestVariance(string s)
    {
        int result=0,n=s.length();
        bool v[26];
        memset(v,false,sizeof(v));
        for(int i=0;i<n;i++) v[s[i]-'a']=true;

        for(int i=0;i<26;i++)
        {
            for(int j=0;j<26;j++)
            {
                if(i==j||!v[i]||!v[j])
                {
                    continue;
                }

                int minimum=0,t=0;
                bool f=false;
                for(int k=0;k<n;k++)
                {
                    if(s[k]-'a'==i) t++;
                    else if(s[k]-'a'==j) t--,f=true;

                    result=max(result,t-minimum-(!f));
                    if(t<minimum) minimum=t,f=false;
                }
            }
        }
        return result;
    }
};