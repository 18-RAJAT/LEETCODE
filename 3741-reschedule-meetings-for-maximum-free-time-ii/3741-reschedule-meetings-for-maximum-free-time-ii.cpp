class Solution{
public:
    int maxFreeTime(int e,vector<int>& s,vector<int>& t){
        int n=s.size(),m=0;
        vector<int>g(n+1),pre(n),suf(n);
        g[0]=s[0];
        for(int i=1;i<n;++i)g[i]=s[i]-t[i-1];
        g[n]=e-t[n-1];
        for(int i=0;i<=n;++i)m=max(m,g[i]);
        vector<int>L(n+1),R(n+1);
        L[0]=0,R[0]=s[0];
        for(int i=1;i<n;++i)L[i]=t[i-1],R[i]=s[i];
        L[n]=t[n-1],R[n]=e;
        int p=0,c=0;
        for(int i=0;i<n;++i)
        {
            while(p<=n && R[p]<=t[i])c=max(c,g[p]),p++;
            pre[i]=c;
        }
        p=n,c=0;
        for(int i=n-1;~i;--i)
        {
            while(p>=0 && L[p]>=s[i])c=max(c,g[p]),p--;
            suf[i]=c;
        }
        int ans=m;
        for(int i=0;i<n;++i)
        {
            int res=t[i]-s[i],l;
            if(n==1)
            {
                (res<=e)?ans=max(ans,e):ans=max(ans,e-res);
                continue;
            }
            // cout<<res<<" "<<pre[i]<<" "<<suf[i]<<endl;
            if(i==0)l=s[1];
            else if(i==n-1)l=e-t[n-2];
            else l=s[i+1]-t[i-1];
            int mxi=0;
            if(i-1>=0)mxi=max(mxi,pre[i-1]);
            if(i+1<n)mxi=max(mxi,suf[i+1]);
            if(mxi>=res)ans=max(ans,l);
            else ans=max(ans,max(0,l-res));
        }
        return ans;
    }
};