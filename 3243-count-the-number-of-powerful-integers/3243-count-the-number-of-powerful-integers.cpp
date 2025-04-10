#define ll long long
class Solution {
public:
    ll dp[16][2];
    ll f(int i,bool eq,const int& lim,const string& r,const string& s)
    {
        if(r.size()<s.size())return 0;
        int n=r.size(),m=s.size();
        if(i==-1)return 1;
        if(~dp[i][eq])return dp[i][eq];
        if(i<m)
        {
            if(eq && (r[n-1-i]<s[m-1-i]))return 0;
            return f(i-1,eq&&(r[n-1-i]==s[m-1-i]),lim,r,s);
        }
        ll cnt=0;
        if(eq)
        {
            for(int j=0;j<=min(lim,r[n-1-i]-'0');++j)
            {
                cnt+=f(i-1,j==(r[n-1-i]-'0'),lim,r,s);
            }
        }
        else
        {
            for(int j=0;j<=lim;++j)
            {
                cnt+=f(i-1,eq,lim,r,s);
            }
        }
        return dp[i][eq]=cnt;
    }

    long long numberOfPowerfulInt(long long start,long long finish,int limit,string s) {
        string a=to_string(finish),b=to_string(start-1);
        for(int i=0;i<16;++i)for(int j=0;j<2;++j)dp[i][j]=-1;
        ll x=f((int)a.size()-1,true,limit,a,s);
        for(int i=0;i<16;++i)for(int j=0;j<2;++j)dp[i][j]=-1;
        ll y=f((int)b.size()-1,true,limit,b,s);
        return x-y;
    }
};