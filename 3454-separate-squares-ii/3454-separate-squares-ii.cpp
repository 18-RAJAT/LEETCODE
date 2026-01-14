class Tree
{
public:
    int n;
    vector<int>F,S,res;
    Tree(vector<int>& c)
    {
        res=c;
        n=c.size()-1;
        F.assign(4*n,0);
        S.assign(4*n,0);
    }
    void update(int id,int l,int r,int prev,int nxt,int x)
    {
        if(prev>r || nxt<l)return;
        if(prev<=l && r<=nxt)
        {
            F[id]+=x;
            if(F[id]>0)S[id]=res[r+1]-res[l];
            else S[id]=l==r?0:S[id*2]+S[id*2+1];
            return;
        }
        int mid=(l+r)/2;
        update(id*2,l,mid,prev,nxt,x);
        update(id*2+1,mid+1,r,prev,nxt,x);
        S[id]=F[id]>=1?res[r+1]-res[l]:S[id*2]+S[id*2+1];
    }
};
class Solution{
public:
    double separateSquares(vector<vector<int>>& squares) {
        int n=squares.size();
        deque<tuple<int,int,int,int>>dq;
        deque<int>ar;
        for(int i=0;i<n;++i)
        {
            int x=squares[i][0],y=squares[i][1],z=squares[i][2];
            dq.push_back({y,1,x,z});
            dq.push_back({y+z,-1,x,z});
            ar.push_back(x);
            ar.push_back(x+z);
        }
        sort(ar.begin(),ar.end());
        ar.erase(unique(ar.begin(),ar.end()),ar.end());
        sort(dq.begin(),dq.end(),[](tuple<int,int,int,int>& a, tuple<int,int,int,int>& b)
        {
            return get<0>(a)==get<0>(b)?get<1>(a)>get<1>(b):get<0>(a)<get<0>(b);
        });
        vector<int>cord(ar.begin(),ar.end());
        Tree seg(cord);
        long double Ans=0.0;
        deque<tuple<long double,long double,long double>>Ndq;
        int res=0,i=0,m=dq.size();
        while(i<m)
        {
            int val=get<0>(dq[i]);
            if(val>res)
            {
                int tmp=seg.S[1],rem=val-res;
                long double area=tmp*(long double)rem;
                Ndq.push_back({(long double)res,(long double)val,(long double)tmp});
                Ans+=area,res=val;
            }
            while(i<m && get<0>(dq[i])==val)
            {
                int l=lower_bound(ar.begin(),ar.end(),get<2>(dq[i]))-ar.begin();
                int r=lower_bound(ar.begin(),ar.end(),get<2>(dq[i])+get<3>(dq[i]))-ar.begin()-1;
                if(l<=r)seg.update(1,0,seg.n-1,l,r,get<1>(dq[i]));
                i++;
            }
        }
        long double tar=Ans/2.0,pos=0.0,Ncord=0.0;
        for(auto& it:Ndq)
        {
            long double y1,y2,u;
            tie(y1,y2,u)=it;
            long double area=u*(y2-y1);
            if(pos+area>=tar)
            {
                Ncord=u==0?y1:y1+(tar-pos)/u;
                return (double)Ncord;
            }
            pos+=area;
        }
        return Ndq.empty()?0.0:(double)get<1>(Ndq.back());
    }
};