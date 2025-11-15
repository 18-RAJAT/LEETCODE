class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size(),ans=0;
        vector<int>zero;
        zero.push_back(-1);
        for(int i=0;i<n;++i)
        {
            if(s[i]=='0')zero.push_back(i);
        }
        zero.push_back(n);
        vector<int>chk(n);
        for(int i=0;i<n;++i)
        {
            auto it=upper_bound(zero.begin(),zero.end(),i);
            chk[i]=*it;
        }
        for(int i=0;i<n;++i)
        {
            int id=i;
            if(s[id]=='1')id=chk[id];
            for(int j=1;1ll*j*j+j<=n;++j)
            {
                if(id==n)break;
                int x=id-i+1-j+chk[id]-id-1;
                if(j*j<=x)
                {
                    int mx=max(id,i+j+j*j-1);
                    ans+=max(0,chk[id]-mx);
                }
                id=chk[id];
            }
        }
        int res=0;
        for(int i=0;i<n;++i)
        {
            if(s[i]=='0')
            {
                ans+=1ll*res*(res+1)/2,res=0;
            }
            else res++;
        }
        ans+=1ll*res*(res+1)/2;
        return ans;
    }
};