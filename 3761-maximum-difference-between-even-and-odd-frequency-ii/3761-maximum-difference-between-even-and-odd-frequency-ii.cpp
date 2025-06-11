const int NN=1000000000;
struct FenwickTree
{
    int size;
    vector<int>tree;
    const int INF=NN;
    FenwickTree():size(0){}
    FenwickTree(int n):size(n),tree(n+1,INF){}
    void init(int n)
    {
        size=n;
        tree.assign(n+1,INF);
    }
    void update(int i,int val)
    {
        for(;i<=size;i+=i&-i) tree[i]=min(tree[i],val);
    }
    int query(int i)
    {
        int res=INF;
        for(;i>0;i-=i&-i)res=min(res,tree[i]);
        return res;
    }
};
class Solution {
public:
    int maxDifference(string s,int k) {
        int n=s.size();
        vector<vector<int>>fz(n+1,vector<int>(5,0));
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<5;++j)
            {
                fz[i+1][j]=fz[i][j];
            }
            fz[i+1][s[i]-'0']++;
        }
        int ans=-NN,INF=NN;
        for(int x=0;x<5;++x)
        {
            for(int y=0;y<5;++y)
            {
                if(x==y)continue;
                vector<int>diff(n+1,0),A(n+1,0),B(n+1,0);
                for(int i=0;i<=n;++i)
                {
                    diff[i]=fz[i][x]-fz[i][y];
                    A[i]=fz[i][x]&1,B[i]=fz[i][y]&1;
                }
                /*
                    calc-> 1 1 2 2 2 1 1 | 0 0 1 1 1 0 0
                    112->122->1122->1222->2211->11221->112211....
                */
                vector<FenwickTree>ft(4,FenwickTree(n+1));
                for(int i=0;i<4;++i)ft[i].init(n+1);
                int best=-NN,pos=0;
                for(int j=k;j<=n;++j)
                {
                    while(pos<=j-k)
                    {
                        int msk=(A[pos]<<1)|B[pos],val=fz[pos][y];
                        // cout<<msk<<" "<<val<<endl;
                        ft[msk].update(val+1,diff[pos]);
                        pos++;
                    }
                    int bit=((1-A[j])<<1)|B[j];
                    if(fz[j][y]>0)
                    {
                        int mn=ft[bit].query(fz[j][y]);
                        if(mn<INF) best=max(best,diff[j]-mn);
                    }
                }
                ans=max(ans,best);
            }
        }
        return ans;
    }
};