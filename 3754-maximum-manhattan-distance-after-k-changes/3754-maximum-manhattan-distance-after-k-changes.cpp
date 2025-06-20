class Solution{
public:
    int maxDistance(string s,int k) {
        int cn=0,cs=0,ce=0,cw=0,ans=0;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='N')cn++;
            else if(s[i]=='S')cs++;
            else if(s[i]=='E')ce++;
            else cw++;
            int base=abs(ce-cw)+abs(cn-cs);
            int cmp=min(ce,cw)+min(cn,cs);
            ans=max(ans,base+2*min(k,cmp));
        }
        return ans;
    }
};