class Solution{
public:
    string generateString(string s,string t){
        int n=s.size(),m=t.size(),l=n+m-1;
        string res(l,'*');
        for(int i=0;i<n;++i)
        {
            if(s[i]=='F')continue;
            for(int j=0,k=i;j<m;++j,++k)
            {
                if(res[k]=='*')res[k]=t[j];
                else if(res[k]!=t[j])return "";
            }
        }
        vector<bool>pos(l,false);
        for(int i=0;i<l;++i)
        {
            if(res[i]=='*'){
                res[i]='a';
                pos[i]=true;
            }
        }
        for(int i=0;i<n;++i)
        {
            if(s[i]=='T')continue;
            string tmp=res.substr(i,m);
            if(tmp!=t)continue;
            bool ok=false;
            for(int j=i+m-1;j>=i;--j)
            {
                if(pos[j] && res[j]==t[j-i])
                {
                    res[j]='b';
                    ok=true;
                    break;
                }
            }
            if(!ok)return "";
        }
        return res;
    }
};