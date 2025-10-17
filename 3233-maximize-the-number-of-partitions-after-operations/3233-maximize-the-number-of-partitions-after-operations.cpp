class Solution
{
public:
    int maxPartitionsAfterOperations(string s,int k)
    {
        if(k==26)return 1;
        int n=s.length();
        vector<int>lm(n),chk(n),tmp(n);
        int msk=0,res=0,ok=1;
        for(int i=0;i<n;++i)
        {
            int bit=1<<(s[i]-'a');
            res|=msk&bit;
            msk|=bit;
            if(__builtin_popcount(msk)>k)
            {
                msk=bit;
                res=0;
                ok++;
            }
            lm[i]=msk;
            chk[i]=res;
            tmp[i]=ok;
        }
        int ans=ok;
        msk=res=ok=0;
        for(int i=n-1;~i;--i)
        {
            int bit=1<<(s[i]-'a');
            res|=msk&bit;
            msk|=bit;
            int btCnt=__builtin_popcount(msk);
            if(k<btCnt)
            {
                msk=bit;
                res=0;
                ok++;
                btCnt=1;
            }
            if(btCnt==k)
            {
                if((bit & res) && (bit & chk[i]) && (__builtin_popcount(lm[i])==k) && ((lm[i] | msk)!=(1<<26)-1))
                {
                    ans=max(ans,ok+tmp[i]+2);
                }
                else if(res)
                {
                    ans=max(ans,ok+tmp[i]+1);
                }
            }
        }
        return ans;
    }
};