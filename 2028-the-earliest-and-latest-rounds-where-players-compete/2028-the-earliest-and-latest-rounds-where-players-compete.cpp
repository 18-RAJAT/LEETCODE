class Solution {
public:
    vector<int> earliestAndLatest(int n,int firstPlayer,int secondPlayer) {
        return recur(n,min(firstPlayer,secondPlayer),max(firstPlayer,secondPlayer));
    }
    vector<int>recur(int n,int l,int r)
    {
        if(l+r==n+1)return{1,1};
        if(l-1>n-r)
        {
            int x=n+1-l;
            l=n+1-r;
            r=x;
        }
        int nxt=(n+1)/2,mx=1,mn=1e9;
        if(r*2<=n+1)
        {
            int pL=l-1,g=r-l-1;
            for(int i=0;i<=pL;++i)
            {
                for(int j=0;j<=g;++j)
                {
                    auto res=recur(nxt,i+1,i+j+2);
                    mn=min(mn,1+res[0]);
                    mx=max(mx,1+res[1]);
                }
            }
        }
        else
        {
            int pR=n+1-r,pL=l-1,m=pR-l-1,g=r-pR-1;
            for(int i=0;i<=pL;++i)
            {
                for(int j=0;j<=m;++j)
                {
                    int x=i+1,y=i+j+1+(g+1)/2+1;
                    auto res=recur(nxt,x,y);
                    mn=min(mn,1+res[0]);
                    mx=max(mx,1+res[1]);
                }
            }
        }
        return{mn,mx};
    }
};